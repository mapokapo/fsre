import csv
from typing import List, Tuple

Row = List[str]
Dataset = List[Row]
Label = str
FeatureName = str
FeatureIndex = int
ModelInput = Tuple[Dataset, List[Label], List[FeatureName], str]


def parse_csv(lines: List[str]) -> ModelInput:
		"""Parse a CSV file from a list of lines.

		Args:
				lines: The lines of the CSV file.

		Returns:
				ModelInput: A tuple containing the dataset, labels, feature names, and label name.
		"""
		reader = list(csv.reader(lines))
		header: List[str] = reader[0]
		rows: Dataset = reader[1:]

		features: List[FeatureName] = header[:-1]
		label_name: FeatureName = header[-1]

		data: Dataset = [row[:-1] for row in rows]
		labels: List[Label] = [row[-1] for row in rows]

		return data, labels, features, label_name