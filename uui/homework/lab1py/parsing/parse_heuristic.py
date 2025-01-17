from typing import Dict, List

HeuristicData = Dict[str, int]

# eg. line: Baderna: 25
def parse_heuristic(lines: List[str]) -> HeuristicData:
		"""Parses the heuristic from the given lines.

		Args:
			lines: The lines to parse.
		
		Returns:
			The heuristic data.

		Raises:
			ValueError: If the heuristic has less than 2 points or any value is negative.
		"""

		heuristic_data: HeuristicData = {}

		for line in lines:
				if line.startswith("#"):
						continue
				
				key, value = line.split(":")
				heuristic_data[key] = int(value.strip())

		if len(heuristic_data) < 2:
				raise ValueError("Heuristic must have at least 2 points")
		
		if any(value < 0 for value in heuristic_data.values()):
				raise ValueError("Heuristic values must be non-negative")
				

		return heuristic_data