from enum import Enum


class Algorithm(Enum):
	"""The algorithms that can be run.

	Attributes:
		bfs: Breadth-first search.
		ucs: Uniform-cost search.
		astar: A* search.
	"""
	
	bfs = "bfs"
	ucs = "ucs"
	astar = "astar"

	def __str__(self):
		return self.value