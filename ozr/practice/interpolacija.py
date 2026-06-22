'''
1. Konstruirajte i nacrtajte interpolacijski polinom koji zadovoljava uvjete:
p(0) = 1; p(2) = 2; p(4) = 3
'''

from math import cos, pi, sin

import numpy as np
import scipy
from numpy.polynomial import polynomial as p

print("### INTERPOLACIJA ###")
print()
print("1. Zadatak")


import matplotlib.pyplot as py  # noqa: E402

A = np.array([
    [1, 0, 0],  # [x^0, x^1, x^2], gdje je x = 0 (iz p(0))
    [1, 2, 4],  # opet: [x^0, x^1, x^2], gdje je x = 2 (iz p(2))
    [1, 4, 16]])  # opet: [x^0, x^1, x^2], gdje je x = 4 (iz p(4))
b = np.array([1, 2, 3])

x = np.linalg.solve(A, b)
print(f"y = {x[0]:.2f} + {x[1]:.2f}x + {x[2]:.2f}x^2")
print(
    f"p(0) = {p.polyval(0, x):.2f}, p(2) = {p.polyval(2, x):.2f}, p(4) = {p.polyval(4, x):.2f}")

domena = np.linspace(-5, 5, 100)

py.plot(domena, np.polynomial.polynomial.polyval(domena, x), label="x")
py.legend()
py.show()

'''
2. Konstruirajte i nacrtajte interpolacijski polinom koji zadovoljava uvjete:
p(1) = 1; p'(1) = 2; p(4) = 3
'''

print()
print("2. Zadatak")

A = np.array([
    [1, 1, 1],
    [0, 1, 2],  # x^0 + x^1 + x^2 derivirano = 0 + 1 + 2x = 1 + 2x = 1 + 2*1 => [a, b, c] = [0, 1, 2]
    [1, 4, 16]])
b = np.array([1, 2, 3])

x = np.linalg.solve(A, b)
print(f"y = {x[0]:.2f} + {x[1]:.2f}x + {x[2]:.2f}x^2")
print(
    f"p(1) = {p.polyval(1, x):.2f}, p'(1) = {p.polyval(1, p.polyder(x)):.2f}, p(4) = {p.polyval(4, x):.2f}")


domena = np.linspace(-5, 5, 100)

py.plot(domena, np.poly1d(x)(domena), label="x")
py.legend()
# py.show()

'''
3. Konstruirajte i nacrtajte polinom koji interpolira vrijednosti funkcije i prve derivacije funkcije sin(x) u čvorovima 0 i π.
'''

print()
print("3. Zadatak")

A = np.array([  # pyright: ignore[reportConstantRedefinition]
    [1, 0, 0, 0],  # x^0 + x^1 + x^2 + x^3, x = 0 (prvi cvor)
    # derivacija od ovog iznad: x^0 + 2x^1 + 3x^2, x = 0 (prvi cvor)
    [0, 1, 0, 0],
    [1, pi, pi**2, pi**3],  # x^0 + x^1 + x^2 + x^3, x = pi (drugi cvor)
    # derivacija od ovog iznad: x^0 + 2x^1 + 3x^2, x = pi (drugi cvor)
    [0, 1, 2*pi, 3*pi**2]
])
# sin(0), sin'(0), sin(pi), sin'(pi)
b = np.array([sin(0), cos(0), sin(pi), cos(pi)])

x = np.linalg.solve(A, b)
print(f"Rjesenje = {x}")

domena = np.linspace(-5, 5, 100)

py.plot(domena, np.poly1d(x)(domena), label="x")
py.legend()
# py.show()

'''
4. Aproksimirajte Lagrangeovim polinomom funkciju xe^x. Interpolirajte funkciju u čvorovima 1, 2, 3 i izračunajte relativnu pogrešku aproksimacije u čvoru 1.5.
'''

print()
print("4. Zadatak")


def f(x):
    return x*np.exp(x)


# l0, l1, l2, i lag uvijek idu po istom sablonu u svakom zadatku - napamet nauciti
def l0(x, x0, x1, x2):
    return (x - x1)*(x - x2)/((x0 - x1)*(x0 - x2))


def l1(x, x0, x1, x2):
    return (x - x0)*(x - x2)/((x1 - x0)*(x1 - x2))


def l2(x, x0, x1, x2):
    return (x - x0)*(x - x1)/((x2 - x0)*(x2 - x1))


def lag(x, x0, x1, x2):
    return f(x0)*l0(x, x0, x1, x2) + f(x1)*l1(x, x0, x1, x2) + f(x2)*l2(x, x0, x1, x2)


print(f"f(1) = {f(1):.2f}, lag(1) = {lag(1, 1, 2, 3):.2f}")
print(f"f(2) = {f(2):.2f}, lag(2) = {lag(2, 1, 2, 3):.2f}")
print(f"f(3) = {f(3):.2f}, lag(3) = {lag(3, 1, 2, 3):.2f}")

prava_vrijednost = f(1.5)
approx_vrijednost = lag(1.5, 1, 2, 3)
abs_greska = abs(approx_vrijednost - prava_vrijednost)
rel_greska = abs_greska/abs(prava_vrijednost)

print(f"lag(1.5) = {lag(1.5, 1, 2, 3):.2f}, apsolutna greska = {abs_greska:.2f}, relativna greska = {rel_greska * 100:.2f}%")


'''
5. Nacrtajte grafove Lagrangeovih baza za čvorove 0, 2, 3
'''

print()
print("5. Zadatak")

domena = np.linspace(-1, 4, 100)  # proizvoljno izabrano

py.plot(domena, l0(domena, 0, 2, 3), label="l0(x)")
py.plot(domena, l1(domena, 0, 2, 3), label="l1(x)")
py.plot(domena, l2(domena, 0, 2, 3), label="l2(x)")
py.legend()
# py.show()

'''
6. Aproksimirajte funkciju 1/(X^2 + 1) na intervalu [0, 5] upotrebom 5, 10, 20 čvorova. Izračunajte relativnu pogrešku u čvoru 0.6.
'''

print()
print("6. Zadatak")


def f(x):
    return 1 / (x**2 + 1)


f_pravo = f(0.6)

domena5 = np.linspace(0, 5, 5)
LPB5 = scipy.interpolate.BarycentricInterpolator(domena5, f(domena5))
LPB5_abs_greska = abs(LPB5(0.6) - f_pravo)
LPB5_rel_greska = LPB5_abs_greska/abs(f_pravo)
print(
    f"5 Cvorova, apsolutna greska = {LPB5_abs_greska:.2f}, relativna greska = {LPB5_rel_greska * 100:.2f}%")

domena10 = np.linspace(0, 5, 10)
LPB10 = scipy.interpolate.BarycentricInterpolator(domena10, f(domena10))
LPB10_abs_greska = abs(LPB10(0.6) - f_pravo)
LPB10_rel_greska = LPB10_abs_greska/abs(f_pravo)
print(
    f"10 Cvorova, apsolutna greska = {LPB10_abs_greska:.6f}, relativna greska = {LPB10_rel_greska * 100:.6f}%")

domena20 = np.linspace(0, 5, 20)
LPB20 = scipy.interpolate.BarycentricInterpolator(domena20, f(domena20))
LPB20_abs_greska = abs(LPB20(0.6) - f_pravo)
LPB20_rel_greska = LPB20_abs_greska/abs(f_pravo)
print(
    f"20 Cvorova, apsolutna greska = {LPB20_abs_greska:.6f}, relativna greska = {LPB20_rel_greska * 100:.6f}%")

'''
7. Aproksimirajte Lagrangeovim polinomom funkciju x^2*e^x. Interpolirajte funkciju u čvorovima 0, 2, 3 i izračunajte apsolutnu pogrešku aproksimacije u čvoru 1 i usporedite sa teoretskom ocjenom pogreške interpolacijskog polinoma.
'''

print()
print("7. Zadatak")


def f(x):
    return x**2 * np.exp(x)


prava_vrijednost = f(1)
approx_vrijednost = lag(1, 0, 2, 3)
abs_greska = abs(prava_vrijednost - approx_vrijednost)
rel_greska = abs_greska/abs(prava_vrijednost)

print(
    f"Prava vrijednost = {prava_vrijednost:.2f}, approx vrijednost = {approx_vrijednost:.2f}, apsolutna greska = {abs_greska:.2f}, relativna greska = {rel_greska * 100:.2f}%")


'''
8. Formirajte Newtonov interpolacijski polinom koji zadovoljava uvjete:
p(0) = -1; p(2) = 2; p(6) = 3
'''

print()
print("8. Zadatak")

matrica = np.zeros([3, 3])
x = np.array([0, 2, 6])

matrica[0, 0] = -1
matrica[1, 0] = 2
matrica[2, 0] = 3

matrica[0, 1] = (matrica[1, 0]-matrica[0, 0])/(x[1]-x[0])
matrica[1, 1] = (matrica[2, 0]-matrica[1, 0])/(x[2]-x[1])

matrica[0, 2] = (matrica[1, 1]-matrica[0, 1])/(x[2]-x[0])


def newton(cvor):
    return matrica[0, 0] + (cvor - x[0])*matrica[0, 1] + (cvor - x[0])*(cvor - x[1])*matrica[0, 2]


print("Vrijednost u x[0]", newton(x[0]))
print("Vrijednost u x[1]", newton(x[1]))
print("Vrijednost u x[2]", newton(x[2]))

'''
9. Formirajte Newtonov interpolacijski polinom koji interpolira funkciju e^x u čvorovima 2, 3, 5 i ocjenite globalnu pogrešku na intervalu.
'''

print()
print("9. Zadatak")

matrica = np.zeros([3, 3])
x = np.array([2, 3, 5])


def f(x):
    return np.exp(x)


matrica[0, 0] = f(x[0])
matrica[1, 0] = f(x[1])
matrica[2, 0] = f(x[2])

matrica[0, 1] = (matrica[1, 0] - matrica[0, 0])/(x[1] - x[0])
matrica[1, 1] = (matrica[2, 0] - matrica[1, 0])/(x[2] - x[1])

matrica[0, 2] = (matrica[1, 1] - matrica[0, 1])/(x[2] - x[0])


def newton2(cvor):
    return matrica[0, 0] + matrica[0, 1]*(cvor - x[0]) + matrica[0, 2]*(cvor - x[0])*(cvor - x[1])


print("Vrijednost polinoma i funkcije u x[0]", newton2(x[0]), f(x[0]))
print("Vrijednost polinoma i funkcije u x[1]", newton2(x[1]), f(x[1]))
print("Vrijednost polinoma i funkcije u x[2]", newton2(x[2]), f(x[2]))

# necemo raditi ocjenu, ali cemo izracunati gresku u cvoru 3.5
abs_greska = abs(f(3.5) - newton(3.5))
rel_greska = abs_greska/abs(f(3.5))

print("Apsolutna i relativna greska u cvoru 3.5 je", abs_greska, rel_greska)

# nacrtati funkciju, polinom, i cvorove na intervalu [1, 6]
domena = np.linspace(1, 6, 100)

py.close("all")
py.plot(domena, f(domena), 'r')
py.plot(domena, newton2(domena), 'b')
py.plot(x, f(x), 'o')
# py.show()

'''
10. Aproksimirajte funkciju 1/(1 + 5x^2) na intervalu [-1, 1] upotrebom 5, 10, 20 čvorova. Izračunajte relativnu pogrešku u čvoru 0.95.
'''

print()
print("10. Zadatak")


def f(x):
    return 1 / (1 + 5 * x**2)


domena5 = np.linspace(-1, 1, 5)
B5 = scipy.interpolate.BarycentricInterpolator(domena5, f(domena5))
B5_abs_greska = abs(f(0.95) - B5(0.95))
B5_rel_greska = B5_abs_greska/abs(f(0.95))

domena10 = np.linspace(-1, 1, 10)
B10 = scipy.interpolate.BarycentricInterpolator(domena10, f(domena10))
B10_abs_greska = abs(f(0.95) - B10(0.95))
B10_rel_greska = B10_abs_greska/abs(f(0.95))

domena20 = np.linspace(-1, 1, 20)
B20 = scipy.interpolate.BarycentricInterpolator(domena20, f(domena20))
B20_abs_greska = abs(f(0.95) - B20(0.95))
B20_rel_greska = B20_abs_greska/abs(f(0.95))

print(
    f"5 Cvorova, apsolutna greska = {B5_abs_greska:.6f}, relativna greska = {B5_rel_greska * 100:.6f}%")
print(
    f"10 Cvorova, apsolutna greska = {B10_abs_greska:.6f}, relativna greska = {B10_rel_greska * 100:.6f}%")
print(
    f"20 Cvorova, apsolutna greska = {B20_abs_greska:.6f}, relativna greska = {B20_rel_greska * 100:.6f}%")
