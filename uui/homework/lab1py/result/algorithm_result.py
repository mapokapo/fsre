from typing import List


class AlgorithmResult:
	def __init__(self, states_visited: int, path_length: int, total_cost: int, path: List[str]):
		self.states_visited = states_visited
		self.path_length = path_length
		self.total_cost = total_cost
		self.path = path