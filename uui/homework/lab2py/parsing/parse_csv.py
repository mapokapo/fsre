import csv
from typing import List

CSVData = List[List[str]]


def parse_csv(lines: list[str]) -> CSVData:
		"""Parse a CSV file from a list of lines.

		Args:
				lines: The lines of the CSV file.

		Returns:
				A list of rows, where each row is a list of strings. Note: the first row is usually the header row.
		"""
		reader = csv.reader(lines)
		return [row for row in reader]