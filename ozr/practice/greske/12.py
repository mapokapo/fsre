# Odrediti apsolutnu i relativnu gresku pri izracunu volumena torusa V = 2ar^2pi^2
# ako je r = 20 +- 0.2 i a = 100 +- 0.5.

from math import pi

r = 20
r_abs_greska = 0.2

a = 100
a_abs_greska = 0.5


def f(r, a):
    return 2*a*r**2*pi**2


def fr(r, a):
    return 4*a*r*pi**2


def fa(r):
    return 2*r**2*pi**2


V_pravo = f(r, a)
V_abs_greska = abs(fr(r, a))*r_abs_greska + abs(fa(r)) * \
    a_abs_greska
V_rel_greska = V_abs_greska/abs(V_pravo)

print(
    f"Prava vrijednost = {V_pravo}, apsolutna greska = {V_abs_greska}, relativna greska = {V_rel_greska * 100:.2f}%")
