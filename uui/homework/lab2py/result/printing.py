from typing import Union

from .result import ID3Result


def print_id3_result(result: ID3Result) -> None:
	# 1. Algorithm must print out the branches in the following format:
	# [BRANCHES]:
	# <tree_level>:<feature_name>=<feature_value> <leaf_value>
	# <tree_level>:<feature_name>=<feature_value> <tree_level+1>:<feature_name>=<feature_value> <leaf_value>
	# <tree_level>:<feature_name>=<feature_value> <tree_level+1>:<feature_name>=<feature_value> ...
	# ...
	print("[BRANCHES]:")
	for layer in result.layers:
		for node in layer:
			if node.is_leaf:
				print(f"{node.leaf_value}")
			else:
				print(f"{node.tree_level}:{node.feature_name}={node.feature_value}", end=" ")
				for child in node.children:
					print(f"{child.tree_level}:{child.feature_name}={child.feature_value}", end=" ")
				print(node.leaf_value)