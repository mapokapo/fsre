from typing import Dict, List, Tuple, Union


class AlgorithmResult:
	def __init__(self, states_visited: int, path_length: int, total_cost: int, path: List[str]):
		self.states_visited = states_visited
		self.path_length = path_length
		self.total_cost = total_cost
		self.path = path

class CheckResult:
	def __init__(self, optimistic_data: Union[Dict[str, Tuple[float, float]], None], consistent_data: Union[Dict[Tuple[str, str], Tuple[float, float, float]], None]):
		self.optimistic_data = optimistic_data
		self.consistent_data = consistent_data
	
	def is_optimistic(self):
		if self.optimistic_data is None:
			raise ValueError("Optimism check data is not available.")

		for _, (heuristic_value, real_value) in self.optimistic_data.items():
			if heuristic_value > real_value:
				return False
		return True
	
	def is_consistent(self):
		if self.consistent_data is None:
			raise ValueError("Consistency check data is not available.")
		
		for _, (heuristic_value, real_value, step_cost) in self.consistent_data.items():
			if heuristic_value > real_value + step_cost:
				return False
		return True