from cli import get_args
from algorithms import run_id3
from parsing import parse_csv
from result import print_id3_result

args = get_args()

training_data = parse_csv(args.training_data.readlines())
testing_data = parse_csv(args.testing_data.readlines())

def main():
	result = run_id3(training_data, testing_data, args.max_depth)

	print_id3_result(result)

# If the script is run directly, call the main function. This prevents the main function from being called when the script is just imported.
if __name__ == "__main__":
  main()
