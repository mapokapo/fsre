from typing import Dict, List, Tuple


# eg. line: Baderna: Višnjan,13 Poreč,14 Pazin,19 Kanfanar,19
# lines starting with # are ignored
# the first 2 lines (after all comments) are the start and end points, eg. "Baderna" and "Višnjan"
def parse_search_space(lines: List[str]) -> Tuple[Tuple[str, str], Dict[str, List[Tuple[str, int]]]]:
		search_space: Dict[str, List[Tuple[str, int]]] = {}

		start = ""
		end = ""
		for line in lines:
				if line.startswith("#"):
						continue
				
				if not start:
						start = line.strip()
						continue
				if not end:
						end = line.strip()
						continue
				
				key, values = line.split(":")
				values = values.strip().split(" ")
				search_space[key] = [(value.split(",")[0], int(value.split(",")[1])) for value in values]

		return (start, end), search_space