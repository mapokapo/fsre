import heapq
from typing import Dict, List, Tuple, Union

from parsing import SearchSpaceData
from result import AlgorithmResult


def run_ucs(search_space_data: SearchSpaceData) -> Union[AlgorithmResult, None]:
	"""Runs the Uniform Cost Search (UCS) algorithm to find the optimal path from the start state to any of the goal states.
	
	Args:
		search_space_data: The search space data.
		
	Returns:
		An AlgorithmResult object containing the number of visited states, the length of the path, the total cost of the path, and the path itself. If the solution is not found, returns None.
	"""

	start_state, goal_states, search_space = search_space_data
	
	# Algorithms must print out their name in the format "# <algorithm>"
	print("# UCS")

	# Priority queue with tuples (cost_so_far, current_state, path_so_far). It is important to remember that the first element of the tuple is the one used for sorting by the heapq module.
	open_list: List[Tuple[int, str, List[str]]] = [(0, start_state, [start_state])]
	visited: Dict[str, int] = {}

	while open_list:
		# Dequeue the first element. The priority queue is a min-heap, so the element with the smallest cost will be dequeued first.
		cost_so_far, current_state, path_so_far = heapq.heappop(open_list)

		# Check if the current state is any of the goal states, and return the result if it is.
		if current_state in goal_states:
				return AlgorithmResult(
						states_visited = len(visited) + 1,
						path_length = len(path_so_far),
						total_cost = cost_so_far,
						path = path_so_far
				)
		
		# Skip the current state if we have already found a shorter path to it
		if visited.get(current_state, float("inf")) <= cost_so_far:
			continue

		visited[current_state] = cost_so_far

		# Expand the current state
		for neighbor, step_cost in search_space.get(current_state, []):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited or new_cost < visited[neighbor]:
				# Enqueue the neighbor with the new cost
				heapq.heappush(open_list, (new_cost, neighbor, path_so_far + [neighbor]))

	# Solution not found
	return None