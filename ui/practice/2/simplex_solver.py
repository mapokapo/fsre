import sys

import numpy as np
from numpy.typing import NDArray

np.set_printoptions(
    suppress=True,
    precision=2,
)

"""
Max Z = 4x1 + 2x2
Subject to:
0.36x1 + 0.24x2 <= 6120
0.72x1 + 0.24x2 <= 1428
0.12x1 + 0.72x2 <= 1428
"""
initial_matrix: NDArray[np.float64] = np.array([
    [6120, 0.36, 0.24],
    [1428, 0.72, 0.24],
    [1428, 0.12, 0.72],
    [0, -4, -2]
])

a = np.concat([initial_matrix[0:3], np.eye(3)], axis=1)
b = np.concat([initial_matrix[3], np.zeros(3)])
matrix = np.vstack([a, b])


def simplex(m: NDArray[np.float64], solution_indices: list[tuple[int, int]] | None = None, i: int = 0):
    if solution_indices is None:
        solution_indices = []

    print(f"\nIteration {i + 1}: ")
    np.savetxt(sys.stdout.buffer, m, fmt="%.2f\t")

    bottom_row = m[-1, 0:]
    if all(n >= 0 for n in bottom_row):
        print("\nFound solution")
        print(
            f"x1,x2 = ({m[solution_indices[0][1], solution_indices[0][0]]}, {m[solution_indices[1][1], solution_indices[1][0]]})")
        return

    (min_bottom_row_value_index, _) = min(
        [(t[0] + 1, t[1]) for t in enumerate(bottom_row[1:])], key=lambda x: x[1])
    pivot_column = m[:, min_bottom_row_value_index]
    (pivot_pos, pivot_value, _) = min([((t[0], min_bottom_row_value_index), t[1], m[:, 0][t[0]] / t[1])
                                       for t in enumerate(pivot_column[0:-1])], key=lambda x: x[2])

    solution_indices.append((0, pivot_pos[1]))

    new_m = m.copy()
    pivot_row = new_m[pivot_pos[1], :]
    pivot_col = new_m[:, pivot_pos[0]]

    for i in range(len(pivot_row)):
        if i == pivot_pos[0]:
            continue

        pivot_row[i] /= pivot_value

    for i in range(len(pivot_col)):
        if i == pivot_pos[1]:
            pivot_col[i] = 1
        else:
            pivot_col[i] = 0

    for x in range(m.shape[0]):
        for y in range(m.shape[1]):
            if x == pivot_pos[0] or y == pivot_pos[1]:
                continue

            new_m[x, y] -= (m[x, pivot_pos[1]] *
                            m[pivot_pos[0], y]) / pivot_value

    simplex(new_m, solution_indices, 1)


simplex(matrix)
