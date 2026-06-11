# Konstruirajte i nacrtajte interpolacijski polinom koji zadovoljava uvjete:
# p(1) = 1; p'(1) = 2; p(4) = 3

import numpy as np
from matplotlib import pyplot

A = np.array([
    [1, 1, 1],
    [0, 1, 2],
    [1, 4, 16]
])
b = np.array([1, 2, 3])

x = np.linalg.solve(A, b)

print(f"Rjesenje = {x}")

domena = np.linspace(0, 5, 100)
pyplot.plot(domena, np.polynomial.polynomial.polyval(
    domena, x), 'r', label="p(x)")
pyplot.plot(domena, np.polynomial.polynomial.polyval(
    domena, np.polynomial.polynomial.polyder(x)), 'b', label="p'(x)")
pyplot.plot([1, 4], np.polynomial.polynomial.polyval(
    [1, 4], x), 'o', label="cvorovi")
pyplot.plot(1, np.polynomial.polynomial.polyval(
    1, np.polynomial.polynomial.polyder(x)), 'o', label="cvorovi (derivacija)")
pyplot.legend()
pyplot.show()
