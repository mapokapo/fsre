import heapq
from typing import Dict, List, Tuple, Union

from parsing import SearchSpaceData
from result import AlgorithmResult


def run_ucs(search_space_data: SearchSpaceData) -> Union[AlgorithmResult, None]:
	start_state, goal_states, search_space = search_space_data
	
	# Algorithms must print out their name in the format "# <algorithm>"
	print("# UCS")

	# Solving the problem using the UCS algorithm

	# Queue with tuples (cost_so_far, current_state, path_so_far)
	open_list: List[Tuple[int, str, List[str]]] = [(0, start_state, [start_state])]
	visited: Dict[str, int] = {}
	states_visited = 0

	while open_list:
		# Dequeue the first element
		cost_so_far, current_state, path_so_far = heapq.heappop(open_list)
		states_visited += 1

		# Check if the current state is any of the goal states
		if current_state in goal_states:
				return AlgorithmResult(
						states_visited = states_visited,
						path_length = len(path_so_far),
						total_cost = cost_so_far,
						path = path_so_far
				)
		
		if visited.get(current_state, float("inf")) <= cost_so_far:
			continue

		visited[current_state] = cost_so_far

		# Expand the current state
		for neighbor, step_cost in search_space.get(current_state, []):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited or new_cost < visited[neighbor]:
				heapq.heappush(open_list, (new_cost, neighbor, path_so_far + [neighbor]))

	# Solution not found
	return None