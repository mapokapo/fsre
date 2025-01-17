from algorithms import run_astar, run_bfs, run_ucs
from cli import Algorithm, get_args
from parsing import parse_heuristic, parse_search_space
from result import print_result

args = get_args()

search_space_data = parse_search_space(args.ss.readlines())
heuristic_data = parse_heuristic(args.h.readlines(), args.h.name) if args.alg == Algorithm.astar else None

def main():
  result = None

  if args.alg == Algorithm.bfs:
    result = run_bfs(search_space_data)
  elif args.alg == Algorithm.ucs:
    result = run_ucs(search_space_data)
  elif args.alg == Algorithm.astar:
    result = run_astar(search_space_data, heuristic_data, args.h.name)
  else:
    print("Invalid algorithm")
    exit(1)
  
  print_result(result)

if __name__ == "__main__":
  main()
