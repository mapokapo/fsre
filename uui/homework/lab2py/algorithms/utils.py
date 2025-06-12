from typing import List, Dict
from collections import Counter, defaultdict
from parsing import Label, Dataset, FeatureIndex
import math

def entropy(labels: List[Label]) -> float:
		"""Calculate the entropy of a list of labels.

		Args:
				labels (List[str]): The list of labels to calculate the entropy for.

		Returns:
				float: The calculated entropy.
		"""
		total: int = len(labels)
		counts: Dict[Label, int] = Counter(labels)
		return -sum((count / total) * math.log2(count / total) for count in counts.values())

def information_gain(data: Dataset, labels: List[Label], feature_index: FeatureIndex) -> float:
		"""Calculate the information gain of a feature.

		Args:
				data (Dataset): The data to calculate the information gain for.
				labels (List[str]): The labels corresponding to the data.
				feature_index (int): The index of the feature to calculate the information gain for.

		Returns:
				float: The calculated information gain.
		"""
		total_entropy: float = entropy(labels)
		subsets: Dict[str, List[Label]] = defaultdict(list)

		for row, label in zip(data, labels):
			feature_val: str = row[feature_index]
			subsets[feature_val].append(label)
		
		weighted_entropy: float = sum((len(subset) / len(labels)) * entropy(subset) for subset in subsets.values())

		return total_entropy - weighted_entropy