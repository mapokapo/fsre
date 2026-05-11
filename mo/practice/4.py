import numpy as np
from scipy.optimize import linprog

f_coefs = np.array([-1500, -1200, -1500])

lhs_coefs = np.array([
    [1, 1, 1],
    [0, 1, 0],
    [5, 4, 8],
    [5, 0, 5]
])

rhs_coefs = np.array([24, 6, 100, 50])

result = linprog(c=f_coefs, A_ub=lhs_coefs, b_ub=rhs_coefs)

if result.x is None or result.fun is None:
    print("No solution found!")
    exit(1)

print(f"({", ".join(f"x{i + 1}" for i in range(len(result.x)))
          }) = ({", ".join((str(n) for n in result.x))})")
print(f"Max Z = {-result.fun}")
