import heapq
from typing import Dict, Tuple

from parsing import HeuristicData, SearchSpace, SearchSpaceData
from result import CheckResult


def dijkstra(search_space: SearchSpace, start: str) -> Dict[str, float]:
	"""Runs Dijkstra's algorithm to find the shortest path from the start state to all other states.
	
	Args:
		search_space: The search space.
		start: The start state.
		
	Returns:
		A dictionary where the keys are the states and the values are the distances from the start state to the corresponding state.
	"""
	# Initialize the distance to all states as infinity
	costs = {state: float("inf") for state in search_space.keys()}
	costs[start] = 0

	# Priority queue with tuples (cost, state)
	pq = [(0, start)]

	while pq:
		# Dequeue the first element. The priority queue is a min-heap, so the element with the smallest cost will be dequeued first.
		current_cost, current_state = heapq.heappop(pq)

		# Skip the current state if we have already found a shorter path to it
		if current_cost > costs[current_state]:
			continue

		for neighbor, step_cost in search_space.get(current_state, []):
			new_cost = current_cost + step_cost

			# Found a shorter path to the neighbor
			if new_cost < costs[neighbor]:
				costs[neighbor] = new_cost
				heapq.heappush(pq, (new_cost, neighbor)) # Enqueue the neighbor with the new cost
		
	return costs


# eg.
# # HEURISTIC-OPTIMISTIC istra_pessimistic_heuristic.txt
# [CONDITION]: [OK] h(Opatija) <= h*: 26.0 <= 44.0
# ...
# [CONDITION]: [ERR] h(Pazin) <= h*: 40.0 <= 38.0
# ...
# [CONCLUSION]: Heuristic is not optimistic.
#
# The format is [CONDITION]: [OK/ERR] h(<state>) <= h*: <heuristic_value> <= <distance_to_state>
def check_optimistic(search_space_data: SearchSpaceData, heuristic_data: HeuristicData, heuristic_file_name: str) -> CheckResult:
	"""Checks if the heuristic is optimistic. A heuristic is optimistic if the heuristic value is less than or equal to the actual shortest path to the nearest goal state.

	Args:
		search_space_data: The search space data.
		heuristic_data: The heuristic data.
		heuristic_file_name: The name of the heuristic file.
	
	Returns:
		A CheckResult object containing the results of the check. The consistent_data field is set to None when checking for an optimistic heuristic.
	"""

	_, goal_states, search_space = search_space_data

	# Checks must print out their name in the format "# <check> <heuristic_file_name>"
	print(f"# HEURISTIC-OPTIMISTIC {heuristic_file_name}")

	optimistic_data: Dict[str, Tuple[float, float]] = {}
	
	for state, heuristic_value in heuristic_data.items():
		# Calculate the distances from the current state to all other states
		distances = dijkstra(search_space, state)

		# Find the shortest distance to any goal state. This will be used as the "real" distance
		actual_distance = min(distances[goal] for goal in goal_states if goal in distances)

		optimistic_data[state] = (heuristic_value, actual_distance)
	
	return CheckResult(optimistic_data = optimistic_data, consistent_data = None)