# Odrediti apsolutnu i relativnu gresku pri izracunu vrijednosti funkcije f(x, y, z) = (xy + xz)/z
# ako je x = 280 +- 0.2, y = 1011325 +- 20, z = 100 +- 0.

x = 280
x_abs_greska = 0.2

y = 1011325
y_abs_greska = 20

z = 100
z_abs_greska = 0


def f(x, y, z):
    return (x*y + x*z)/z


def fx(y, z):
    return (y + z)/z


def fy(x, z):
    return x/z


f_pravo = f(x, y, z)
f_abs_greska = abs(fx(y, z))*x_abs_greska + abs(fy(x, z)) * \
    y_abs_greska
f_rel_greska = f_abs_greska/abs(f_pravo)

print(
    f"Prava vrijednost = {f_pravo}, apsolutna greska = {f_abs_greska}, relativna greska = {f_rel_greska * 100:.2f}%")
