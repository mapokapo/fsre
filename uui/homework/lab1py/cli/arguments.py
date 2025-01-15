from typing import TextIO

from . import Algorithm


class Arguments():
	alg: Algorithm
	ss: TextIO
	h: TextIO
	check_optimistic: bool
	check_consistent: bool