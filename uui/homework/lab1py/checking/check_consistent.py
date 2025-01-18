from typing import Dict, Tuple

from parsing import HeuristicData, SearchSpaceData
from result import CheckResult


# eg.
# # HEURISTIC-CONSISTENT istra_pessimistic_heuristic.txt
# [CONDITION]: [OK] h(Baderna) <= h(Višnjan) + c: 25.0 <= 20.0 + 13.0
# ...
# [CONDITION]: [ERR] h(Lupoglav) <= h(Buzet) + c: 35.0 <= 0.0 + 15.0
# ...
# [CONCLUSION]: Heuristic is not consistent.
#
# The format is: [CONDITION]: [OK/ERR] h(<state1>) <= h(<state2>) + c: <heuristic_value1> <= <heuristic_value2> + <real_value>
def check_consistent(search_space_data: SearchSpaceData, heuristic_data: HeuristicData, heuristic_file_name: str) -> CheckResult:
	"""Checks if the heuristic is consistent. A heuristic is consistent if the heuristic value of a state is less than or equal to the heuristic value of its successor plus the cost of the step between them. Simply, this checks if the heuristic adheres to the triangle inequality.
	
	Args:
		search_space_data: The search space data.
		heuristic_data: The heuristic data.
		heuristic_file_name: The name of the heuristic file.
	
	Returns:
		A CheckResult object containing the results of the check. The optimistic_data field is set to None when checking for a consistent heuristic.
	"""

	# Checks must print out their name in the format "# <check> <heuristic_file_name>"
	print(f"# HEURISTIC-CONSISTENT {heuristic_file_name}")

	# Calculate the consistent data structure
	consistent_data: Dict[Tuple[str, str], Tuple[float, float, float]] = {}

	for state1, heuristic_value1 in heuristic_data.items():
		for state2, step_cost in search_space_data[2].get(state1, []):
			heuristic_value2 = heuristic_data.get(state2, 0)
			consistent_data[(state1, state2)] = (heuristic_value1, heuristic_value2, step_cost)
			
	return CheckResult(optimistic_data = None, consistent_data = consistent_data)