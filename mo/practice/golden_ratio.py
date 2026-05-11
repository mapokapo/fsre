
import math
from typing import Callable


def f(x: float):
    return 3 * x**3 + 2 * x**2 - 3*x


Func = Callable[[float], float]


def golden_ratio_search(f: Func, a: float, b: float, e: float, is_max: bool):
    L = b - a

    rho = ((1 - math.sqrt(5)) / 2)**2

    print(f"Using square inverse Golden Ratio {rho:.6f}")

    x0 = a + rho * L
    x1 = b - rho * L

    while abs(L) > e:
        x0 = a + rho * L
        x1 = b - rho * L

        print(f"x0 = {x0:.6f}, x1 = {x1:.6f}")

        if f(x0) > f(x1):
            if is_max:
                b = x1
                x1 = x0
                L = b - a
                x0 = a + rho * L
            else:
                a = x0
                x0 = x1
                L = b - a
                x1 = b - rho * L
        else:
            if is_max:
                a = x0
                x0 = x1
                L = b - a
                x1 = b - rho * L
            else:
                b = x1
                x1 = x0
                L = b - a
                x0 = a + rho * L

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

result = golden_ratio_search(f, a, b, e, is_max=False)

print(f"Found solution at ({result:.6f}, {f(result):.6f})")
