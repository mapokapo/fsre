from typing import Union, Dict
from parsing import Label, FeatureName

class ID3Node:
	def __init__(self, is_leaf: bool = False, prediction: Union[Label, None] = None, feature_name: Union[FeatureName, None] = None, children: Dict[str, "ID3Node"] = None):
		"""Initialize a Node in the decision tree.

		Args:
			is_leaf (bool): Whether the node is a leaf node.
			prediction (str): The prediction label if the node is a leaf.
			feature_name (str): The feature name if the node is not a leaf.
			children (dict): A dictionary mapping feature values to child nodes.
		"""
		self.is_leaf = is_leaf
		self.prediction = prediction
		self.feature_name = feature_name
		self.children = children if children is not None else {}