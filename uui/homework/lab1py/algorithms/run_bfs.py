from typing import List, Set, Tuple, Union

from parsing import SearchSpaceData
from result import AlgorithmResult


def run_bfs(search_space_data: SearchSpaceData) -> Union[AlgorithmResult, None]:
	start_state, goal_states, search_space = search_space_data

	# 1. Algorithm must print out its name in the format "# <algorithm>"
	print("# BFS")

	# Solving the problem using the BFS algorithm

	# Queue with tuples (current_state, path_so_far, cost_so_far)
	open_list: List[Tuple[str, List[str], int]] = [(start_state, [start_state], 0)]
	visited: Set[str] = set()
	states_visited = 0

	while open_list:
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

		if current_state in visited:
			continue
		
		visited.add(current_state)

		# Expand the current state
		# In BFS, we sort the neighbors alphabetically before adding them to the queue. The queue itself is never sorted entirely, only the chunks of neighbors that are added at once.
		for neighbor, step_cost in sorted(search_space.get(current_state, []), key=lambda x: x[0]):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited:
				open_list.append((neighbor, path_so_far + [neighbor], new_cost))
	
	# Solution not found
	return None