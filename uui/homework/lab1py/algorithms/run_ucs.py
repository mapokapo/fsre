from typing import Dict, List, Tuple, Union

from parsing import SearchSpaceData
from result import AlgorithmResult


def run_ucs(search_space_data: SearchSpaceData) -> Union[AlgorithmResult, None]:
	start_state, goal_states, search_space = search_space_data

	# 1. Algorithm must print out its name in the format "# <algorithm>"
	print("# UCS")

	# Solving the problem using the UCS algorithm

	# Queue with tuples (current_state, path_so_far, cost_so_far)
	open_list: List[Tuple[str, List[str], int]] = [(start_state, [start_state], 0)]
	visited: Dict[str, int] = {}
	states_visited = 0

	while open_list:
		# Sort the open list by cost
		open_list.sort(key=lambda x: x[2])

		# Dequeue the first element
		current_state, path_so_far, cost_so_far = open_list.pop(0)
		states_visited += 1

		# Check if the current state is any of the goal states
		if current_state in goal_states:
				return AlgorithmResult(
						states_visited = states_visited,
						path_length = len(path_so_far),
						total_cost = cost_so_far,
						path = path_so_far
				)
		
		if current_state in visited and visited[current_state] <= cost_so_far:
			continue

		visited[current_state] = cost_so_far

		# Expand the current state
		for neighbor, step_cost in search_space.get(current_state, []):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited or new_cost < visited[neighbor]:
				open_list.append((neighbor, path_so_far + [neighbor], new_cost))

	# Solution not found
	return None