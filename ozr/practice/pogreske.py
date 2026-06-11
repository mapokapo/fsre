'''
1. Zadan je rezultat mjerenja x = 20.5 ± 0.7, odredite relativnu grešku.
'''

from decimal import Decimal, getcontext

print("### POGRESKE ###")
print()
print("1. Zadatak")

x = 20.5
x_abs_greska = 0.7

x_rel_greska = x_abs_greska/abs(x)
print(f"Relativna greska je {x_rel_greska * 100:.2f}%")

'''
2. Zaokružite broj π na tri decimale, zatim odredite apsolutnu i relativnu grešku aproksimacije.
'''

print()
print("2. Zadatak")

from math import log, pi  # noqa: E402

pi_approx = round(pi, 3)
pi_abs_greska = abs(pi - pi_approx)
pi_rel_greska = pi_abs_greska/abs(pi)
print(
    f"pi_approx = {pi_approx}, apsolutna greska = {pi_abs_greska:.6f}, relativna greska = {pi_rel_greska * 100:.6f}%")

'''
3. Izračunajte sumu niza prvih 10^6 članova niza a_i = 1/i, i = 1, ..., izračunajte apsolutnu i relativnu grešku za sumu unaprijed i unazad. Referentno rješenje izračunajte aritmetikom s povećanom točnošću.
'''

print()
print("3. Zadatak")

niz = [1/i for i in range(1, 10**6 + 1, 1)]
suma_unaprijed = sum(niz)
suma_unazad = sum(reversed(niz))

getcontext().prec = 50

precizni_niz = [1/Decimal(i) for i in range(1, 10**6 + 1, 1)]
precizna_suma_unaprijed = sum(precizni_niz)
precizna_suma_unazad = sum(reversed(precizni_niz))

abs_greska_unaprijed = abs(Decimal(suma_unaprijed) - precizna_suma_unaprijed)
rel_greska_unaprijed = abs_greska_unaprijed/precizna_suma_unaprijed

abs_greska_unazad = abs(Decimal(suma_unazad) - precizna_suma_unazad)
rel_greska_unazad = abs_greska_unazad/precizna_suma_unazad

print(f"Suma unaprijed = {suma_unaprijed}, suma unazad = {suma_unazad}, apsolutna greska unaprijed = {abs_greska_unaprijed}, apsolutna greska unazad = {abs_greska_unazad}, relativna greska unaprijed = {rel_greska_unaprijed}, relativna greska unazad = {rel_greska_unazad}")

'''
4. Izračunajte sumu niza prvih 10^6 članova niza a_i = 1/(i^2), i = 1, ..., izračunajte apsolutnu i relativnu grešku za sumu unaprijed i unazad. Referentno rješenje izračunajte aritmetikom s povećanom točnošću.
'''

print()
print("4. Zadatak")

niz = [1/(i**2) for i in range(1, 10**6 + 1, 1)]
suma_unaprijed = sum(niz)
suma_unazad = sum(reversed(niz))

getcontext().prec = 50

precizni_niz = [1/(Decimal(i)**2) for i in range(1, 10**6 + 1, 1)]
precizna_suma_unaprijed = sum(precizni_niz)
precizna_suma_unazad = sum(reversed(precizni_niz))

abs_greska_unaprijed = abs(Decimal(suma_unaprijed) - precizna_suma_unaprijed)
rel_greska_unaprijed = abs_greska_unaprijed/precizna_suma_unaprijed

abs_greska_unazad = abs(Decimal(suma_unazad) - precizna_suma_unazad)
rel_greska_unazad = abs_greska_unazad/precizna_suma_unazad

print(f"Suma unaprijed = {suma_unaprijed}, suma unazad = {suma_unazad}, apsolutna greska unaprijed = {abs_greska_unaprijed}, apsolutna greska unazad = {abs_greska_unazad}, relativna greska unaprijed = {rel_greska_unaprijed}, relativna greska unazad = {rel_greska_unazad}")

'''
5. Odredite relativnu i apsolutnu grešku pri izračunu vrijednosti funkcije f(x, y, z) = 2xy + z^3 * y ako je x = 8.00 ± 0.1, y = 3.00 ± 0.04, z = 2.40 ± 0.05.
'''

print()
print("5. Zadatak")


def f(x, y, z):
    return 2*x*y + z**3*y


def f_derivirano_po_x(x):
    return 2*x


def f_derivirano_po_y(x, z):
    return 2*x + z**3


def f_derivirano_po_z(y, z):
    return 3*y*z**2


x = 8
x_abs_greska = 0.1

y = 3
y_abs_greska = 0.04

z = 2.4
z_abs_greska = 0.05

f_pravo = f(x, y, z)
f_abs_greska = abs(f_derivirano_po_x(x))*x_abs_greska + abs(f_derivirano_po_y(x, z)
                                                            )*y_abs_greska + abs(f_derivirano_po_z(y, z))*z_abs_greska
f_rel_greska = f_abs_greska/abs(f_pravo)

print(
    f"f(x, y, z) = {f_pravo}, apsolutna greska = {f_abs_greska:.2f}, relativna greska = {f_rel_greska * 100:.2f}%")

'''
6. Odredite relativnu i apsolutnu grešku pri izračunu vrijednosti funkcije f(x, y, z) = (xy + xz)/z ako je x = 280 ± 0.2, y = 1011325 ± 20, z = 100.
'''

print()
print("6. Zadatak")


def f(x, y, z):
    return (x*y + x*z)/z


def f_derivirano_po_x(y, z):
    return (y * z)/z


def f_derivirano_po_y(x, z):
    return x/z

# nije potrebno derivirati z jer se nece uopce koristiti (na kraju se mnozi sa z_abs_greska = 0)


x = 280
x_abs_greska = 0.2

y = 1011325
y_abs_greska = 20

z = 100
z_abs_greska = 0

f_pravo = f(x, y, z)
f_abs_greska = abs(f_derivirano_po_x(y, z))*x_abs_greska + \
    abs(f_derivirano_po_y(x, z))*y_abs_greska + z_abs_greska
f_rel_greska = f_abs_greska/abs(f_pravo)

print(
    f"f(x, y, z) = {f_pravo}, apsolutna greska = {f_abs_greska:.2f}, relativna greska = {f_rel_greska * 100:.2f}%")

'''
7. Odredite apsolutnu i relativnu grešku pri izračunavanju volumena torusa V = 2a(r^2)*(𝜋^2) koji nastaje rotacijom kruga radijusa r, čije je središte za a udaljeno od centra rotacije ako je r = 20.00 ± 0.2, a = 100 ± 0.5.
'''

print()
print("7. Zadatak")


def volumen_torusa(r, a):
    return 2*a*r**2*pi**2


def volumen_torusa_derivirano_po_r(r, a):
    return 4*a*r*pi**2


def volumen_torusa_derivirano_po_a(r):
    return 2*r**2*pi**2


r = 20
r_abs_greska = 0.2

a = 100
a_abs_greska = 0.5

V_pravo = volumen_torusa(r, a)
V_abs_greska = abs(volumen_torusa_derivirano_po_r(
    r, a))*r_abs_greska + abs(volumen_torusa_derivirano_po_a(r))*a_abs_greska
V_rel_greska = V_abs_greska/abs(V_pravo)

print(
    f"V = {V_pravo:.2f}, apsolutna greska = {V_abs_greska:.2f}, relativna greska = {V_rel_greska * 100:.2f}%")

'''
8.Izračunajte apsolutnu i relativnu uvjetovanost funkcije f(x) = ln(x) u okolini točke x_0 = 2.
'''

print()
print("8. Zadatak")


def f(x):
    return log(x)


def f_derivirano(x):
    return 1/x  # derivacija ln(x) je 1/x


x0 = 2

f_pravo = f(x0)
f_abs_uvjetovanost = abs(f_derivirano(x0))
f_rel_uvjetovanost = abs(x0*f_derivirano(x0)/f_pravo)

print(
    f"f(x) = {f_pravo:.2f}, apsolutna uvjetovanost = {f_abs_uvjetovanost:.2f}, relativna uvjetovanost = {f_rel_uvjetovanost:.2f}")
