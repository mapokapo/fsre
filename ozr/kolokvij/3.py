'''
LU dekompozicijom riješi sustav gdje su matrica sustava A i vektor b dani s  
A=[ [1   2    3]
      [8    4    0]  
      [6    0    7]],
b=[2    2    3] .
Uz to izračunajte uvjetovanost sustava u normi ∞
'''

from math import inf

import numpy as np
import scipy

A = np.array([
    [1, 2, 3],
    [8, 4, 0],
    [6, 0, 7]
])
b = np.array([2, 2, 3])

uvjetovanost = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost (inf) = {uvjetovanost}")

P, L, U = scipy.linalg.lu(A)

# P.T je potrebno jer je konvencija u scipy: A = P @ L @ U
y = np.linalg.solve(L, np.dot(P.T, b))
x = np.linalg.solve(U, y)

print(f"Rjesenje sustava = {x}")

# provjera
rjesenje = np.linalg.solve(A, b)
print(f"Ispravno: {np.allclose(rjesenje, x)}")
