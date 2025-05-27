from parsing import CSVData
from result import ID3Result
from sklearn.tree import DecisionTreeClassifier, _tree
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score, confusion_matrix
import numpy as np
from collections import Counter
from typing import List

class ID3Model:
	def __init__(self, max_depth: int):
		self.max_depth = max_depth
		if max_depth > 0:
			self.classifier = DecisionTreeClassifier(
				criterion='entropy',
				max_depth=self.max_depth,
			)
		else:
			self.classifier = None
		self.feature_names = []
		self.encoders = []
		self.label_encoder = LabelEncoder()
		self.train_majority = None
	
	def fit(self, training_data: CSVData) -> None:
		"""Fit the ID3 model to the training data.

		Args:
			training_data (CSVData): The training data to fit the model on. The first row is a header row, containing the feature names, except the last column, which is the name of the label.
		"""
		header, *data = training_data
		features_raw = [row[:-1] for row in data]
		labels_raw = [row[-1] for row in data]

		# Store the majority class for training
		self.train_majority = Counter(labels_raw).most_common(1)[0][0]
		if self.max_depth <= 0:
			# no tree to fit
			return

		# Encode features
		self.feature_names = header[:-1]
		features: List[List[int]] = []
		for col in zip(*features_raw):
				label_encoder = LabelEncoder().fit(col)
				self.encoders.append(label_encoder)
				features.append(label_encoder.transform(col))
		features = np.vstack(features).T

		# Encode labels
		labels = self.label_encoder.fit_transform(labels_raw)


		# Fit the classifier
		self.classifier.fit(features, labels)
	
	def _extract(self, node, path, branches):
		tree = self.classifier.tree_
		if tree.feature[node] != _tree.TREE_UNDEFINED:
			f_idx = tree.feature[node]
			# for each category value at this split, recur
			classes = self.encoders[f_idx].classes_
			# left child: values <= threshold code
			left_ids = [i for i in range(len(classes)) if i <= tree.threshold[node]]
			right_ids = [i for i in range(len(classes)) if i > tree.threshold[node]]
			for cat in classes[left_ids]:
				self._extract(tree.children_left[node], path+[(len(path)+1, self.feature_names[f_idx], cat)], branches)
			for cat in classes[right_ids]:
				self._extract(tree.children_right[node], path+[(len(path)+1, self.feature_names[f_idx], cat)], branches)
		else:
			counts = tree.value[node][0]
			maj_idx = np.argmax(counts)
			label = self.label_encoder.inverse_transform([maj_idx])[0]
			# format path
			segs = [f"{lvl}:{feat}={val}" for lvl, feat, val in path]
			branches.append(" ".join(segs + [label]))
	
	def predict(self, testing_data: CSVData) -> ID3Result:
		"""Predict the labels for the testing data using the fitted model.

		Args:
			testing_data (CSVData): The testing data to predict labels for. The first row is a header row, containing the feature names, except the last column, which is the name of the label.

		Returns:
			ID3Result: The result of the ID3 algorithm, containing the decision tree and the accuracy on the testing data.
		"""
		header, *data = testing_data
		features_raw = [row[:-1] for row in data]
		labels_raw = [row[-1] for row in data]

		# encode test, handle unseen by using global majority
		# special case depth=0
		if self.max_depth == 0:
			branches = [self.train_majority]
			predictions = [self.train_majority] * len(labels_raw)
			accuracy = accuracy_score(labels_raw, predictions)
			label_names = sorted(set(labels_raw) | set(predictions))
			cm = confusion_matrix(labels_raw, predictions, labels=label_names).tolist()
			return ID3Result(branches, predictions, accuracy, cm)
	
		features = []
		for j, col in enumerate(zip(*features_raw)):
				label_encoder = self.encoders[j]
				encoded_col = [label_encoder.transform([value])[0] if value in label_encoder.classes_ else -1 for value in col]
				features.append(encoded_col)
		features = np.vstack(features).T

		# predict
		label_predicted = self.classifier.predict(features)
		labels = self.label_encoder.inverse_transform(label_predicted)

		# extract branches
		branches = []
		self._extract(0, [], branches)

		# accuracy
		accuracy = accuracy_score(labels_raw, labels)

		# confusion matrix
		label_names = sorted(set(labels_raw) | set(labels))
		cm = confusion_matrix(labels_raw, labels, labels=label_names)
		return ID3Result(branches, list(labels), accuracy, cm.tolist())