from parsing import ModelInput
from result import ID3Result
from .id3_model import ID3Model


def run_id3(training_data: ModelInput, testing_data: ModelInput, max_depth: int) -> ID3Result:
	"""Runs a ID3 workflow (training + testing) on the provided data.
	
	Args:
		training_data: The training data to use for building the decision tree.
		testing_data: The testing data to use for evaluating the decision tree.
		
	Returns:
		ID3Result: The result of the ID3 algorithm, containing the decision tree and the accuracy on the testing data.
	"""
 
	dataset, labels, feature_names, label_name = training_data
 
	# Create and train the ID3 model.
	id3 = ID3Model()
	id3.fit(dataset, labels, feature_names, max_depth)
	
	# Predict the labels using the testing data.
	result = id3.predict(testing_data[0], testing_data[1])

	return result