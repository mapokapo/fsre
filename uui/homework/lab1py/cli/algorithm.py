from enum import Enum


class Algorithm(Enum):
	bfs = "bfs"
	ucs = "ucs"
	astar = "astar"

	def __str__(self):
		return self.value