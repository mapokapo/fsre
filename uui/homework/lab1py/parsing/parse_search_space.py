from typing import Dict, List, Tuple, Union

SearchSpace = Dict[str, List[Tuple[str, int]]]
SearchSpaceData = Tuple[str, List[str], SearchSpace]

# eg. line: Baderna: Višnjan,13 Poreč,14 Pazin,19 Kanfanar,19
# a line can also contain no values, eg. line: Baderna:
# lines starting with # are ignored
# the first 2 lines (after all comments) are the start and end points, eg. "Baderna" and "Višnjan"

def parse_search_space(lines: List[str]) -> SearchSpaceData:
		"""Parses the search space from the given lines.

		Args:
			lines: The lines to parse.

		Returns:
			A tuple containing the start state, all possible goal states, and the search space.

		Raises:
			ValueError: If the start or goal points are not found, the search space has less than 2 points, any distance is negative, or the start or goal point(s) are not found in the search space.
		"""

		search_space: SearchSpace = {}
		
		start_state: Union[str, None] = None
		goal_states: Union[List[str], None] = None
		for line in lines:
				if line.startswith("#"):
						continue
				
				if not start_state:
						start_state = line.strip()
						continue
				if not goal_states:
						goal_states = line.strip().split(" ")
						continue
				
				key, values = map(str.strip, line.split(":"))
				values = None if len(values) == 0 else values.split(" ")
				search_space[key] = [] if values is None else [(value.split(",")[0], int(value.split(",")[1])) for value in values]

		if not start_state or not goal_states:
				raise ValueError("Start and goal points not found")
		
		if len(search_space) < 2:
				raise ValueError("Search space must have at least 2 points")
		
		if any(value[1] < 0 for values in search_space.values() for value in values):
				raise ValueError("Distances must be non-negative")
		
		if start_state not in search_space or any(goal_state not in search_space for goal_state in goal_states):
				raise ValueError("Start or goal points not found in search space")

		return start_state, goal_states, search_space