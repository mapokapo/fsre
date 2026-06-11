# Konstruirajte i nacrtajte interpolacijski polinom koji zadovoljava uvjete:
# p(0) = 1; p(2) = 2; p(4) = 3

import numpy as np
from matplotlib import pyplot

A = np.array([
    [1, 0, 0],
    [1, 2, 4],
    [1, 4, 16]
])
b = np.array([1, 2, 3])

x = np.linalg.solve(A, b)

print(f"Rjesenje = {x}")

domena = np.linspace(-1, 5, 100)
pyplot.plot(domena, np.polynomial.polynomial.polyval(
    domena, x), 'r', label="p(x)")
pyplot.plot([0, 2, 4], np.polynomial.polynomial.polyval(
    [0, 2, 4], x), 'o', label="cvorovi")
pyplot.legend()
pyplot.show()
