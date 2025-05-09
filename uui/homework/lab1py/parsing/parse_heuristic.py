from typing import Dict, List

HeuristicData = Dict[str, int]

# eg. line: Baderna: 25
# lines starting with # are ignored
def parse_heuristic(lines: List[str]) -> HeuristicData:
		"""Parses the heuristic from the given lines.

		Args:
			lines: The lines to parse.
		
		Returns:
			The heuristic data. The data is a dictionary where the keys are the states and the values are the heuristic values. Heuristic values are approximations of the cost to reach the goal state from the current state.

		Raises:
			ValueError: If the heuristic has less than 2 points or any value is negative.
		"""

		heuristic_data: HeuristicData = {}

		for line in lines:
				# Skip comments
				if line.startswith("#"):
						continue
				
				key, value = line.split(":")
				heuristic_data[key] = int(value.strip())

		# Heuristic must have at least 2 points (minimum number of points in order to create a path)
		if len(heuristic_data) < 2:
				raise ValueError("Heuristic must have at least 2 points")
		
		if any(value < 0 for value in heuristic_data.values()):
				raise ValueError("Heuristic values must be non-negative")
				

		return heuristic_data