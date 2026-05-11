import matplotlib.pyplot as plt
import numpy as np


def f(x: float):
    return x**3 - 2*x - 5


def df1(x: float):
    return 3 * x**2 - 2


def df2(x: float):
    return 6*x


x0: float = 2
e: float = 0.01
N: int = 20

i: int = 1
while True:
    df2x = df2(x0)

    if df2x == 0:
        print("Division by zero!")
        exit(1)

    df1x = df1(x0)
    x1 = x0 - df1x / df2x
    print(f"Iteration {i}: x1 = {x1:.6f}, f(x1) = {f(x1):.6f}")

    x0 = x1

    i += 1
    if i >= N:
        print("Function divergent!")
        exit(1)

    if abs(df1x) < e:
        print(f"Found optimum: ({x1:.6f}, {f(x1):.6f})")
        break

fig, ax = plt.subplots()

a = np.arange(-3, 3, 0.01)
f_vec = np.vectorize(f)
df1_vec = np.vectorize(df1)
df2_vec = np.vectorize(df2)

ax.plot(a, f_vec(a), 'r', label="f(x)")
ax.plot(a, np.zeros(a.shape), 'g', label="f'(x)")
ax.plot(x1, f(x1), 'bo', label="x1")
ax.plot(2, f(2), 'go', label="x0")
ax.annotate(f"({x1:.4f}, {f(x1):.4f})",
            (x1, f(x1)), ha="center", va="bottom")

ax.set_title("Result")
ax.set_xlabel("x-osa")
ax.set_ylabel("y-osa")
ax.set_xlim(-3, 3)
ax.set_ylim(-20, 20)
ax.legend()
ax.grid()

plt.show()
