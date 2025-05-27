from typing import TextIO

class Arguments():
	"""The parsed CLI arguments.

	Attributes:
		training_data (str): The path to the training data file.
		testing_data (str): The path to the testing data file.
		--max_depth (int): The maximum depth of the decision tree.
	"""
	
	training_data: TextIO
	testing_data: TextIO
	max_depth: int