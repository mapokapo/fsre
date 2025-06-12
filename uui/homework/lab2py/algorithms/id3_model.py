from parsing import FeatureName, Label, Dataset, Row
from collections import deque, defaultdict, Counter
from result import ID3Result
from .id3_node import ID3Node
from .utils import information_gain
from typing import List, Tuple, Dict, Union, Set

class ID3Model:
	def __init__(self):
		self.tree: Union[ID3Node, None] = None
		self.features: List[FeatureName] = []
	
	def fit(
		self, 
		dataset: Dataset,
		labels: List[Label],
		features: List[FeatureName],
		max_depth: int = 3
	) -> None:
		"""Fit the ID3 model to the training dataset.

		Args:
			dataset (Dataset): The training data to fit the model on.
			labels (List[Label]): The labels corresponding to the training data.
			features (List[FeatureName]): The names of the features in the dataset.
			max_depth (int): The maximum depth of the decision tree. If less than 1, the tree will be a single leaf node with the majority label.
		"""
		self.features = features[:]
  
		if max_depth < 1:
			majority_label: Label = Counter(labels).most_common(1)[0][0]
			self.tree = ID3Node(is_leaf=True, prediction=majority_label)
			return
  
		self.tree = self._build_tree(dataset, labels, features, max_depth)

	def _build_tree(
		self,
		dataset: Dataset,
		labels: List[Label],
		features: List[FeatureName],
		max_depth: int
  ) -> ID3Node:
		root = ID3Node()
		queue: deque[Tuple[ID3Node, Dataset, List[Label], List[FeatureName], int]] = deque()
		queue.append((root, dataset, labels, features, 0))

		while queue:
			current_node, current_data, current_labels, current_features, depth = queue.popleft()

			if len(set(current_labels)) == 1 or depth == max_depth or not current_features:
				prediction: Label = Counter(current_labels).most_common(1)[0][0]
				current_node.is_leaf = True
				current_node.prediction = prediction
				continue

			best_gain: float = -1
			best_idx: int = -1
			for idx, _ in enumerate(current_features):
				gain: float = information_gain(current_data, current_labels, idx)
				if gain > best_gain:
					best_gain = gain
					best_idx = idx

			if best_gain == 0:
				prediction: Label = Counter(current_labels).most_common(1)[0][0]
				current_node.is_leaf = True
				current_node.prediction = prediction
				continue

			best_feature_name: FeatureName = current_features[best_idx]
			current_node.feature_name = best_feature_name
			current_node.children = {}

			# Group by feature value
			partitions: Dict[str, Tuple[Dataset, List[Label]]] = defaultdict(lambda: ([], []))
			for row, label in zip(current_data, current_labels):
				feature_val: str = row[best_idx]
				reduced_row: Row = row[:best_idx] + row[best_idx + 1:]
				partitions[feature_val][0].append(reduced_row)
				partitions[feature_val][1].append(label)

			for feature_val, (subset_data, subset_labels) in partitions.items():
				child_node = ID3Node()
				current_node.children[feature_val] = child_node

				reduced_features = current_features[:best_idx] + current_features[best_idx + 1:]
				queue.append((child_node, subset_data, subset_labels, reduced_features, depth + 1))

		return root

	def _predict_with_path(self, node: ID3Node, row: Row, features: List[FeatureName]) -> Tuple[Label, List[str]]:
		path: List[str] = []
		depth: int = 1

		if node.is_leaf:
			return node.prediction, [str(node.prediction)]  # Will become the single branch

		while not node.is_leaf:
			if node.feature_name not in features:
				return node.prediction, path  # unknown feature
			
			idx: int = features.index(node.feature_name)
			val: str = row[idx]

			path.append(f"{depth}:{node.feature_name}={val}")
			depth += 1

			if val not in node.children:
				return node.prediction, path  # unknown value

			node = node.children[val]
			row = row[:idx] + row[idx + 1:]
			features = features[:idx] + features[idx + 1:]

		path.append(str(node.prediction))  # Add the final prediction to the path
		return node.prediction, path

	def predict(self, dataset: Dataset, true_labels: List[Label]) -> ID3Result:
		"""Uses the fitted model to predict labels for each row in the dataset and returns the predictions along with the accuracy and confusion matrix.

		Args:
			dataset (Dataset): The dataset to predict labels for.
			true_labels (List[Label]): The true labels corresponding to the dataset.
   
		Returns:
			ID3Result: The prediction result containing the predicted label, feature names, and the path taken in the tree.
		"""
		predictions: List[Label] = []
		unique_branches: Set[str] = set()
		cm_counts: Dict[Tuple[Label, Label], int] = defaultdict(int)

		for row, true_label in zip(dataset, true_labels):
			pred, path = self._predict_with_path(self.tree, row, self.features)
			predictions.append(pred)

			# Build the full path string from path list
			branch_str = " ".join(path)
			unique_branches.add(branch_str)
			
			cm_counts[(true_label, pred)] = cm_counts.get((true_label, pred), 0) + 1

		# Compute accuracy
		correct: int = sum(1 for pred, true in zip(predictions, true_labels) if pred == true)
		accuracy: float = correct / len(true_labels) if true_labels else 0.0

		# Build confusion matrix (as strings)
		all_labels = sorted(set(true_labels + predictions))
		confusion_matrix: List[List[str]] = []
		for actual in all_labels:
			row = [str(cm_counts.get((actual, predicted), 0)) for predicted in all_labels]
			confusion_matrix.append(row)

		return ID3Result(
			branches=sorted(unique_branches),
			predictions=predictions,
			accuracy=accuracy,
			confusion_matrix=confusion_matrix
    )