# Definirajte Lagrangeove baze i Lagrangeovim polinomom interpolirajte funkciju f(x) = 2sin(x) u čvorovima 0, 1, 2.
# Nacrtajte graf funkcije i Lagrangeov polinom i označite čvorove.
# Izračunajte apsolutnu i relativnu pogrešku u čvoru 0.99.


import numpy as np
from matplotlib import pyplot


def f(x):
    return 2 * np.sin(x)


def l0(x, x0, x1, x2):
    return (x - x1)*(x - x2)/((x0 - x1)*(x0 - x2))


def l1(x, x0, x1, x2):
    return (x - x0)*(x - x2)/((x1 - x0)*(x1 - x2))


def l2(x, x0, x1, x2):
    return (x - x0)*(x - x1)/((x2 - x0)*(x2 - x1))


def lag(x, x0, x1, x2):
    return f(x0)*l0(x, x0, x1, x2) + f(x1)*l1(x, x0, x1, x2) + f(x2)*l2(x, x0, x1, x2)


f_prava = f(0.99)
f_lag = lag(0.99, 0, 1, 2)

f_lag_abs_greska = abs(f_prava - f_lag)
f_lag_rel_greska = f_lag_abs_greska/abs(f_prava)

print(f"Vrijednost f(0.99) = {f_prava:.6f}, aproksimacija = {f_lag:.6f}")
print(
    f"Apsolutna pogreska = {f_lag_abs_greska:.6f}, relativna pogreska = {f_lag_rel_greska * 100:.6f}%")

domena = np.linspace(-5, 5, 100)
pyplot.plot(domena, f(domena), 'r', label="f(x)")
pyplot.plot(domena, lag(domena, 0, 1, 2), 'b', label="lag(x)")
pyplot.plot([0, 1, 2], f([0, 1, 2]), 'o', label="cvorovi")
pyplot.legend()
pyplot.show()
