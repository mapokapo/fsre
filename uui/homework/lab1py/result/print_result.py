from typing import Union

from . import AlgorithmResult


def print_result(result: Union[AlgorithmResult, None]) -> None:
	# 1. Algorithm must print out if a solution was found in the format "[FOUND_SOLUTION]: yes" or "[FOUND_SOLUTION]: no"
	if result is not None:
		print("[FOUND_SOLUTION]: yes")

		# 2. Algorithm must print out the number of states visited in the format "[STATES_VISITED]: <number>"
		print("[STATES_VISITED]:", result.states_visited)

		# 3. Algorithm must print out the length of the found solution in the format "[PATH_LENGTH]: <number>"
		print("[PATH_LENGTH]:", result.path_length)

		# 4. Algorithm must print out the cost of the found solution in the format "[TOTAL_COST]: <number>"
		print("[TOTAL_COST]:", result.total_cost)

		# 5. Algorithm must print out the path of the found solution in the format "[PATH]: <state1> => <state2> => ... => <stateN>"
		print("[PATH]:", " => ".join(result.path))
	else:
		print("[FOUND_SOLUTION]: no")