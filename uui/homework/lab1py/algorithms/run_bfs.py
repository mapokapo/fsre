from typing import List, Set, Tuple, Union

from parsing import SearchSpaceData
from result import AlgorithmResult


def run_bfs(search_space_data: SearchSpaceData) -> Union[AlgorithmResult, None]:
	"""Runs the Breadth-First Search (BFS) algorithm to find the optimal path from the start state to any of the goal states.
	
	Args:
		search_space_data: The search space data.
	
	Returns:
		An AlgorithmResult object containing the number of visited states, the length of the path, the total cost of the path, and the path itself. If the solution is not found, returns None.
	"""
	
	start_state, goal_states, search_space = search_space_data

	# Algorithms must print out their name in the format "# <algorithm>"
	print("# BFS")

	# List with tuples (current_state, path_so_far, cost_so_far)
	open_list: List[Tuple[str, List[str], int]] = [(start_state, [start_state], 0)]
	visited: Set[str] = set()

	while open_list:
		# Remove the first element. We don't use a priority queue in BF, so we don't need to sort the list.
		current_state, path_so_far, cost_so_far = open_list.pop(0)

		# Check if the current state is any of the goal states, and return the result if it is.
		if current_state in goal_states:
				return AlgorithmResult(
						states_visited = len(visited) + 1,
						path_length = len(path_so_far),
						total_cost = cost_so_far,
						path = path_so_far
				)

		# Skip the current state if we have already visited it
		if current_state in visited:
			continue
		
		visited.add(current_state)

		# Expand the current state
		# In BFS, we sort the neighbors alphabetically before adding them to the queue. The queue itself is never sorted entirely, only the chunks of neighbors that are added at once. This is also why we don't need a priority queue nor the heapq module.
		for neighbor, step_cost in sorted(search_space.get(current_state, []), key=lambda x: x[0]):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited:
				open_list.append((neighbor, path_so_far + [neighbor], new_cost))
	
	# Solution not found
	return None