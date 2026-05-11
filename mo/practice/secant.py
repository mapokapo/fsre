from typing import Callable


def f(x: float):
    return 3 * x**3 + 2 * x**2 - 3*x


def g(x: float):
    return 9 * x**2 + 4*x - 3


Func = Callable[[float], float]


def secant(f: Func, x0: float, x1: float, e: float, N: int):
    xn0 = x0
    xn1 = x1
    for i in range(N):
        if f(xn0) == f(xn1):
            print("Division by zero error!")
            return None

        xn = xn1 - (xn1 - xn0) * f(xn1) / (f(xn1) - f(xn0))
        print(f"Iteration {i}: xn = {xn:.6f}, f(xn) = {f(xn):.6f}")

        xn0 = xn1
        xn1 = xn

        if abs(f(xn)) < e:
            print("Found solution")
            return xn


x0 = float(input("Enter first guess: "))
x1 = float(input("Enter second guess: "))
e = float(input("Enter error tolerance: "))
N = int(input("Enter maximum number of steps: "))

result = secant(g, x0, x1, e, N)
if result is None:
    print("Solution not found!")
    exit(1)

print(f"Found solution at ({result:.6f}, {f(result):.6f})")
