from parsing import CSVData
from result import ID3Result

class ID3Model:
	def __init__(self, max_depth: int):
		self.max_depth = max_depth
	
	def fit(self, training_data: CSVData) -> None:
		"""Fit the ID3 model to the training data.

		Args:
			training_data (CSVData): The training data to fit the model on. The first row is a header row, containing the feature names, except the last column, which is the name of the label.
		"""
		pass
	
	def predict(self, testing_data: CSVData) -> ID3Result:
		"""Predict the labels for the testing data using the fitted model.

		Args:
			testing_data (CSVData): The testing data to predict labels for. The first row is a header row, containing the feature names, except the last column, which is the name of the label.

		Returns:
			ID3Result: The result of the ID3 algorithm, containing the decision tree and the accuracy on the testing data.
		"""
		pass