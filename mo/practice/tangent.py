from typing import Callable


def f(x: float):
    return 3 * x**3 + 2 * x**2 - 3*x


def Df1(x: float):
    return 9 * x**2 + 4*x - 3


def Df2(x: float):
    return 18*x + 4


Func = Callable[[float], float]


def tangent(f: Func, g: Func, x0: float, e: float, N: int):
    xn = x0
    for i in range(N):
        if g(xn) == 0:
            print("Division by zero error!")
            return None

        xn = xn - f(xn) / g(xn)
        print(f"Iteration {i}: xn = {xn:.6f}, f(xn) = {f(xn):.6f}")

        if abs(f(xn)) < e:
            print("Solution found")
            return xn


x0 = float(input("Enter initial guess: "))
e = float(input("Enter error tolerance: "))
N = int(input("Enter maximum number of steps: "))

result = tangent(Df1, Df2, x0, e, N)
if result is None:
    print("Solution not found!")
    exit(1)

print(f"Found solution at ({result:.6f}, {f(result):.6f})")
