from typing import Union

from .result import AlgorithmResult, CheckResult


def print_algorithm_result(result: Union[AlgorithmResult, None]) -> None:
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

def print_check_result(result: CheckResult) -> None:
	if result.consistent_data is not None:
		# Print out each condition in the format "[CONDITION]: [ERR] h(<state1>) <= h(<state2>) + c: <heuristic_value1> <= <heuristic_value2> + <cost>"
		for (state1, state2), (heuristic_value1, heuristic_value2, step_cost) in result.consistent_data.items():
			print(f"[CONDITION]: [{'OK' if heuristic_value1 <= heuristic_value2 + step_cost else 'ERR'}] h({state1}) <= h({state2}) + c: {heuristic_value1} <= {heuristic_value2} + {step_cost}")
		
		# Print out the conclusion in the format "[CONCLUSION]: Heuristic is not consistent." or "[CONCLUSION]: Heuristic is consistent."
		print(f"[CONCLUSION]: Heuristic is {'' if result.is_consistent() else 'not '}consistent.")
	elif result.optimistic_data is not None:
		# Print out each condition in the format "[CONDITION]: [ERR] h(<state>) <= h*: <heuristic_value> <= <real_value>"
		for state, (heuristic_value, real_value) in result.optimistic_data.items():
			print(f"[CONDITION]: [{'OK' if heuristic_value <= real_value else 'ERR'}] h({state}) <= h*: {heuristic_value} <= {real_value}")
		
		# Print out the conclusion in the format "[CONCLUSION]: Heuristic is not optimistic." or "[CONCLUSION]: Heuristic is optimistic."
		print(f"[CONCLUSION]: Heuristic is {'' if result.is_optimistic() else 'not '}optimistic.")
	else:
		raise ValueError("Invalid CheckResult object provided.")