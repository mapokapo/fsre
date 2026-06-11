# Odredite polinom koji zadovoljava uvjete:
# p(1) = 4; p'(1) = 2, p(2) = 5
# Odredite vrijednost polinoma u 3 i vrijednost prve derivacije u 3.

import numpy as np
from numpy.polynomial import polynomial as p

A = np.array([
    [1, 1, 1],
    [0, 1, 2],
    [1, 2, 4]
])
b = np.array([4, 2, 5])

x = np.linalg.solve(A, b)

print(f"Rjesenje = {x}")
print(f"Vrijednost u x = 3: {p.polyval(3, x)}")
print(f"Vrijednost prve derivacije u x = 3: {p.polyval(3, p.polyder(x))}")
