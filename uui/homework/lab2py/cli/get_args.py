import argparse

from .arguments import Arguments
from .utils import is_valid_file

parser = argparse.ArgumentParser()
parser.add_argument("training_data", help="Path to file containing the training data", metavar="TRAIN", type=lambda x: is_valid_file(parser, x))
parser.add_argument("testing_data", help="Path to file containing the testing data", metavar="TEST", type=lambda x: is_valid_file(parser, x))
parser.add_argument("max_depth", help="Maximum depth of the decision tree (default: 5)", metavar="DEPTH", type=int, default=5, nargs="?")

def get_args():
	"""Parse the command line arguments and return them.

	CLI Args:
		training_data: Path to file containing the training data (required)
		testing_data: Path to file containing the testing data (required)
		max_depth: Maximum depth of the decision tree (default: 5)
	
	Returns:
		Arguments: The parsed arguments.
	
	The programs exits with an error if the required arguments are not provided correctly.
	"""

	args: Arguments = parser.parse_args()
	
	return args