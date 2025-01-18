from typing import Union

from algorithms import run_astar, run_bfs, run_ucs
from checking import check_consistent, check_optimistic
from cli import Algorithm, get_args
from parsing import parse_heuristic, parse_search_space
from result import (AlgorithmResult, CheckResult, print_algorithm_result,
                    print_check_result)

args = get_args()

search_space_data = parse_search_space(args.ss.readlines())
heuristic_data = parse_heuristic(args.h.readlines())

def main():
  # Heuristic checking flow
  if args.check_consistent or args.check_optimistic:
    result: CheckResult

    if args.check_consistent:
      result = check_consistent(search_space_data, heuristic_data, args.h.name)
    elif args.check_optimistic:
      result = check_optimistic(search_space_data, heuristic_data, args.h.name)
    
    print_check_result(result) # result is guaranteed to not be None here
  # Algorithm flow
  else:
    result: Union[AlgorithmResult, None] = None

    if args.alg == Algorithm.bfs:
      result = run_bfs(search_space_data)
    elif args.alg == Algorithm.ucs:
      result = run_ucs(search_space_data)
    elif args.alg == Algorithm.astar:
      result = run_astar(search_space_data, heuristic_data, args.h.name)
    else:
      # This should never happen
      print("Invalid algorithm")
      exit(1)
  
    print_algorithm_result(result)

# If the script is run directly, call the main function. This prevents the main function from being called when the script is just imported.
if __name__ == "__main__":
  main()
