from .result import ID3Result


def print_id3_result(result: ID3Result) -> None:
	print("[BRANCHES]:")
	for branch in result.branches:
		print(branch)
	
	print("[PREDICTIONS]:", " ".join(result.predictions))

	print(f"[ACCURACY]: {result.accuracy:.5f}")

	print("[CONFUSION_MATRIX]:")
	for row in result.confusion_matrix:
		print(" ".join(str(value) for value in row))