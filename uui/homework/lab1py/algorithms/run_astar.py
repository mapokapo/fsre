from typing import List, Set, Tuple, Union

from parsing import HeuristicData, SearchSpaceData
from result import AlgorithmResult


def run_astar(search_space_data: SearchSpaceData, heuristic_data: HeuristicData, heuristic_file_name: str) -> Union[AlgorithmResult, None]:
	start_state, goal_states, search_space = search_space_data

	# Algorithms must print out their name in the format "# <algorithm>"
	# A* algorithm additionally must print out the name of the file used for the heuristic
	print(f"# A-STAR {heuristic_file_name}")

	# Solving the problem using the A* algorithm

	# Queue with tuples (current_state, path_so_far, cost_so_far)
	open_list: List[Tuple[str, List[str], int]] = [(start_state, [start_state], 0)]
	visited: Set[str] = set()
	states_visited = 0

	while open_list:
		# Sort the open list based on cost + heuristic. Heuristic shouldn't impact the total cost of the path, and is only used to sort the open list.
		open_list.sort(key=lambda x: x[2] + heuristic_data.get(x[0], 0))

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
		for neighbor, step_cost in search_space.get(current_state, []):
			new_cost = cost_so_far + step_cost

			if neighbor not in visited:
				open_list.append((neighbor, path_so_far + [neighbor], new_cost))

	# Solution not found
	return None
