# Aproksimirajte Lagrangeovim polinomom funkciju xe^x. Interpolirajte funkciju u čvorovima 1, 2, 3 i izračunajte relativnu pogrešku aproksimacije u čvoru 1.5.

import numpy as np


def f(x):
    return x * np.exp(x)


def l0(x, x0, x1, x2):
    return (x - x1)*(x - x2)/((x0 - x1)*(x0 - x2))


def l1(x, x0, x1, x2):
    return (x - x0)*(x - x2)/((x1 - x0)*(x1 - x2))


def l2(x, x0, x1, x2):
    return (x - x0)*(x - x1)/((x2 - x0)*(x2 - x1))


def lag(x, x0, x1, x2):
    return f(x0)*l0(x, x0, x1, x2) + f(x1)*l1(x, x0, x1, x2) + f(x2)*l2(x, x0, x1, x2)


f_prava = f(1.5)
f_approx = lag(1.5, 1, 2, 3)

print(f"Vrijednost funkcije u x = 1.5: {f_prava}, approx: {f_approx}")

f_approx_absgr = abs(f_prava - f_approx)
f_approx_relgr = f_approx_absgr/abs(f_prava)

print(
    f"Apsolutna greska = {f_approx_absgr:.2f}, relativna greska = {f_approx_relgr * 100:.2f}%")
