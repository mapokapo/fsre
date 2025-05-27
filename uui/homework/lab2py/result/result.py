from typing import List


class ID3Result:
	def __init__(self, branches: List[str], predictions: List[str], accuracy: float, confusion_matrix: List[List[str]]):
		self.branches = branches
		self.predictions = predictions
		self.accuracy = accuracy
		self.confusion_matrix = confusion_matrix