from typing import List

Branches = List[str]
Predictions = List[str]
ConfusionMatrix = List[List[str]]

class ID3Result:
	def __init__(self, branches: Branches, predictions: Predictions, accuracy: float, confusion_matrix: ConfusionMatrix):
		self.branches = branches
		self.predictions = predictions
		self.accuracy = accuracy
		self.confusion_matrix = confusion_matrix