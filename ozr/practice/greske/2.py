# Ispitajte uvjetovanost matrice [[2, 0, 0], [0, -3, 3], [0, 3, 5]] u 2 i inf normi.
from math import inf

import numpy as np

A = np.array([
    [2, 0, 0],
    [0, -3, 3],
    [0, 3, 5]
])

uvjetovanost_2 = np.linalg.norm(A, 2) * np.linalg.norm(np.linalg.inv(A), 2)

print(f"Uvjetovanost (2) = {uvjetovanost_2}")

uvjetovanost_inf = np.linalg.norm(
    A, inf) * np.linalg.norm(np.linalg.inv(A), inf)

print(f"Uvjetovanost (inf) = {uvjetovanost_inf}")
