from .result import ID3Result


def print_id3_result(result: ID3Result) -> None:
	# 1. Algorithm must print out the branches in the following format:
	# [BRANCHES]:
	# <tree_level>:<feature_name>=<feature_value> <leaf_value>
	# <tree_level>:<feature_name>=<feature_value> <tree_level+1>:<feature_name>=<feature_value> <leaf_value>
	# <tree_level>:<feature_name>=<feature_value> <tree_level+1>:<feature_name>=<feature_value> ...
	# ...
	print("[BRANCHES]:")
	for branch in result.branches:
		print(branch)
	
	print("[PREDICTIONS]:", " ".join(result.predictions))

	print(f"[ACCURACY]: {result.accuracy:.5f}")

	print("[CONFUSION_MATRIX]:")
	for row in result.confusion_matrix:
		print(" ".join(str(value) for value in row))