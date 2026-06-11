# Konstruirajte i nacrtajte polinom koji interpolira vrijednosti funkcije i prve derivacije funkcije sin(x) u čvorovima 0 i π.

from math import pi

import numpy as np
from matplotlib import pyplot

# p(x) = sin(x)
# p'(x) = cos(x)
# p(0) = 0; p'(0) = 1; p(pi) = 0; p'(pi) = -1
A = np.array([
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [1, pi, pi**2, pi**3],
    [0, 1, 2*pi, 3*pi**2]
])
b = np.array([0, 1, 0, -1])

x = np.linalg.solve(A, b)

print(f"Rjesenje = {x}")

domena = np.linspace(-1, 4, 100)
pyplot.plot(domena, np.sin(domena), 'r', label="sin(x)")
pyplot.plot(domena, np.cos(domena), 'b', label="cos(x)")
pyplot.plot([0, pi], np.sin([0, pi]), 'o')
pyplot.plot([0, pi], np.cos([0, pi]), 'o')
pyplot.legend()
pyplot.show()
