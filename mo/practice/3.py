import math

import matplotlib.pyplot as plt
import numpy as np


def f(x: float):
    return -math.e**(-x) - 1


x0: float = 0
x1: float = 1
e: float = 0.01
N: int = 20

i: int = 1

while True:
    if f(x0) == f(x1):
        print("Division by zero!")
        exit(1)

    x2 = x0 - (((x1 - x0) * f(x0)) / (f(x1) - f(x0)))
    print(f"Iteration {i}: x2 = {x2:.6f}, f(x2) = {f(x2):.6f}")

    x0 = x1
    x1 = x2

    i += 1
    if i >= N:
        print("Function divergent!")
        exit(1)

    if abs(f(x2)) < e:
        print(f"Found optimum: ({x2:.6f}, {f(x2):.6f})")
        break

a = np.arange(-3, 3, 0.01)
f_vec = np.vectorize(f)
b = f_vec(a)

fig, ax = plt.subplots()

ax.plot(a, b, 'r', label="f(x)")
ax.plot(x2, f(x2), 'bo', label="x2")

ax.set_title("Result")
ax.set_xlabel("x-axis")
ax.set_ylabel("y-axis")
ax.legend()
ax.grid()

plt.show()
