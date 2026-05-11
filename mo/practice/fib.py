
from typing import Callable


def f(x: float):
    return 3 * x**3 + 2 * x**2 - 3*x


Func = Callable[[float], float]


def fib_search(f: Func, a: float, b: float, e: float, is_max: bool):
    def fib(n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        return fib(n-1) + fib(n-2)

    L = b - a

    n = 0
    while fib(n) <= L/e:
        n += 1

    print(f"Using Fibonacci number index {n}")

    x0 = a + (fib(n-2)/fib(n)) * L
    x1 = a + (fib(n-1)/fib(n)) * L

    for i in range(1, n - 1):
        x0 = a + (fib(n-2)/fib(n)) * L
        x1 = a + (fib(n-1)/fib(n)) * L

        print(f"Iteration {i}: x0 = {x0:.6f}, x1 = {x1:.6f}")

        if f(x0) > f(x1):
            if is_max:
                b = x1
                x1 = x0
                L = b - a
                x0 = a + (fib(n-2)/fib(n)) * L
            else:
                a = x0
                x0 = x1
                L = b - a
                x1 = a + (fib(n-1)/fib(n)) * L
        else:
            if is_max:
                a = x0
                x0 = x1
                L = b - a
                x1 = a + (fib(n-1)/fib(n)) * L
            else:
                b = x1
                x1 = x0
                L = b - a
                x0 = a + (fib(n-2)/fib(n)) * L

    if f(x0) > f(x1):
        if is_max:
            return x0
        else:
            return x1
    else:
        if is_max:
            return x1
        else:
            return x0


a = float(input("Enter lower bound: "))
b = float(input("Enter upper bound: "))
e = float(input("Enter error tolerance: "))

result = fib_search(f, a, b, e, is_max=True)

print(f"Found solution at ({result:.6f}, {f(result):.6f})")
