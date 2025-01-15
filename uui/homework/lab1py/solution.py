from cli import get_args
from parsing import parse_search_space

args = get_args()

search_space = parse_search_space(args.ss.readlines())

def main():
  print(f'Start: {search_space[0][0]}')
  print(f'End: {search_space[0][1]}')
  print("Search space:")
  for key, values in search_space[1].items():
    print(f'\t{key}: {values}')

if __name__ == "__main__":
  main()
