from typing import TextIO

from . import Algorithm


class Arguments():
	"""The parsed CLI arguments.

	Attributes:
		alg: The algorithm to run.
		ss: The search space file.
		h: The heuristic file.
		check_optimistic: Whether to check if the heuristic is optimistic.
		check_consistent: Whether to check if the heuristic is consistent.
	"""
	
	alg: Algorithm
	ss: TextIO
	h: TextIO
	check_optimistic: bool
	check_consistent: bool