# LU dekompozicijom rijesi sustave:
# a)
# A = [[0, 7, 8], [0, 2, 1], [3, 0, -1]]
# b = [2, 3, 1]
# b)
# A = isto, b = [-1, 5, 2]

import numpy as np
import scipy

# a)
A = np.array([
    [0, 7, 8],
    [0, 2, 1],
    [3, 0, -1]
])
b = np.array([2, 3, 1])

P, L, U = scipy.linalg.lu(A)

y = np.linalg.solve(P @ L, b)
x = np.linalg.solve(U, y)

print(f"Rjesenje = {x}")

# b)
b = np.array([-1, 5, 2])

y = np.linalg.solve(P @ L, b)
x = np.linalg.solve(U, y)

print(f"Rjesenje = {x}")
