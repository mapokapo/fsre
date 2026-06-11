# Akproksimirajte funkciju f(x) = x/(cos(x)+2) na intervalu [0,2] Lagrangeovim polinomom najviše stupnja 2, korištenjem Baricentričnih koordinata.
# Nacrtajte graf funkcije, Lagrangeov polinom i označite čvorove.
# Izračunajte apsolutnu i relativnu pogrešku u čvoru 0.32.

import numpy as np
import scipy
from matplotlib import pyplot


def f(x):
    return x / (np.cos(x) + 2)


domena = np.linspace(0, 2, 3)

LB = scipy.interpolate.BarycentricInterpolator(domena, f(domena))

f_prava = f(0.32)
f_approx = LB(0.32)

f_approx_abs_greska = abs(f_prava - f_approx)
f_approx_rel_greska = f_approx_abs_greska/abs(f_prava)

print(f"Vrijednost x = 0.32: {f_prava:.2f}, aproksimacija: {f_approx:.2f}")
print(
    f"Apsolutna greska aproksimacije = {f_approx_abs_greska:.2f}, relativna greska aproksimacije = {f_approx_rel_greska * 100:.2f}%")

x_os = np.linspace(-1, 3, 100)
pyplot.plot(x_os, f(x_os), 'r', label="f(x)")
pyplot.plot(x_os, LB(x_os), 'b', label="LB(x)")
pyplot.plot(domena, f(domena), 'o', label="cvorovi")
pyplot.legend()
pyplot.show()
