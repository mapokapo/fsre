# Odrediti apsolutnu i relativnu gresku pri izracunu vrijednosti funkcije f(x, y, z) = 2xy + z^3y
# ako je x = 8 +- 0.1, y = 3 +- 0.04, z = 2.4 +- 0.05.

x = 8
x_abs_greska = 0.1

y = 3
y_abs_greska = 0.04

z = 2.4
z_abs_greska = 0.05


def f(x, y, z):
    return 2*x*y + z**3*y


def fx(y):
    return 2*y


def fy(x, z):
    return 2*x + z**3


def fz(y, z):
    return 3*y*z**2


f_pravo = f(x, y, z)
f_abs_greska = abs(fx(y))*x_abs_greska + abs(fy(x, z)) * \
    y_abs_greska + abs(fz(y, z))*z_abs_greska
f_rel_greska = f_abs_greska/abs(f_pravo)

print(
    f"Prava vrijednost = {f_pravo}, apsolutna greska = {f_abs_greska}, relativna greska = {f_rel_greska * 100:.2f}%")
