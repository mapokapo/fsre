import argparse

from .algorithm import Algorithm
from .arguments import Arguments
from .utils import is_valid_file

parser = argparse.ArgumentParser()
parser.add_argument("--alg", help="Algorithm to run", type=Algorithm, choices=list(Algorithm))
parser.add_argument("--ss", help="Path to file containing the search space", metavar="FILE", type=lambda x: is_valid_file(parser, x))
parser.add_argument("--h", help="Path to file containing the heuristic", metavar="FILE", type=lambda x: is_valid_file(parser, x))
parser.add_argument("--check-optimistic", help="Check if the heuristic is optimistic", action="store_true")
parser.add_argument("--check-consistent", help="Check if the heuristic is consistent", action="store_true")

def get_args():
	args: Arguments = parser.parse_args()

	if args.alg is None and args.check_consistent is False and args.check_optimistic is False:
		parser.error("one of the arguments --alg, --check-optimistic, --check-consistent is required")

	if args.alg == Algorithm.bfs or args.alg == Algorithm.ucs:
		if not args.ss:
			parser.error(f"the following arguments are required: --ss")
	elif args.alg == Algorithm.astar:
		if not args.ss or not args.h:
			parser.error(f"the following arguments are required: --ss, --h")
	
	if (args.check_optimistic or args.check_consistent) and (not args.ss or not args.h):
		parser.error(f"the following arguments are required: --ss, --h")
	
	return args