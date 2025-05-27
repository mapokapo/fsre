from parsing import CSVData
from result import ID3Result
from .id3_model import ID3Model


def run_id3(training_data: CSVData, testing_data: CSVData, max_depth: int) -> ID3Result:
	"""Runs a ID3 workflow (training + testing) on the provided data.
	
	Args:
		training_data: The training data to use for building the decision tree.
		testing_data: The testing data to use for evaluating the decision tree.
		
	Returns:
		ID3Result: The result of the ID3 algorithm, containing the decision tree and the accuracy on the testing data.
	"""	
	# Create and train the ID3 model.
	id3 = ID3Model(max_depth)
	id3.fit(training_data)
	
	# Predict the labels using the testing data.
	result = id3.predict(testing_data)

	return result