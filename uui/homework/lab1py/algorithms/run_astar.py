from typing import List, Set, Tuple, Union

from parsing import HeuristicData, SearchSpaceData
from result import AlgorithmResult


def run_astar(search_space_data: SearchSpaceData, heuristic_data: HeuristicData, heuristic_file_name: str) -> Union[AlgorithmResult, None]:
	"""Runs the A* algorithm to find the optimal path from the start state to any of the goal states.
	
	Args:
		search_space_data: The search space data.
		heuristic_data: The heuristic data.
		heuristic_file_name: The name of the heuristic file. Used for printing the name of the heuristic in the output.
	
	Returns:
		An AlgorithmResult object containing the number of visited states, the length of the path, the total cost of the path, and the path itself. If the solution is not found, returns None.
	"""

	start_state, goal_states, search_space = search_space_data

	# Algorithms must print out their name in the format "# <algorithm>"
	# A* algorithm additionally must print out the name of the file used for the heuristic
	print(f"# A-STAR {heuristic_file_name}")

	# List with tuples (current_state, path_so_far, cost_so_far)
	open_list: List[Tuple[str, List[str], int]] = [(start_state, [start_state], 0)]
	visited: Set[str] = set()

	while open_list:
		# Sort the open list based on cost + heuristic. We don't use the heapq (priority queue) module here because we need to sort the list based on a custom computed value, instead of one that is already present in the tuple. This inflicts a performance penalty, but it is necessary for the A* algorithm.
		open_list.sort(key=lambda x: x[2] + heuristic_data.get(x[0], 0))

		# Remove the first element
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
		for neighbor, step_cost in search_space.get(current_state, []):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited:
				open_list.append((neighbor, path_so_far + [neighbor], new_cost))

	# Solution not found
	return None
