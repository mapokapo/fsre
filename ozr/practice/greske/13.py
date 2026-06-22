# Odrediti apsolutnu i relativnu uvjetovanost funkcije f(x) = ln(x) u okolini tocke x = 2.

from math import log


def f(x):
    return log(x)


def fx(x):
    return 1/x


x = 2

f_abs_uvjetovanost = abs(fx(x))
f_rel_uvjetovanost = abs(x * f_abs_uvjetovanost)/abs(f(x))

print(
    f"Apsolutna uvjetovanost = {f_abs_uvjetovanost}, relativna uvjetovanost = {f_rel_uvjetovanost * 100:.2f}%")
