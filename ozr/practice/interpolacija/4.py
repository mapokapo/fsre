# Newtonovim polinomom aproksimirajte funkciju f(x) = x/(cos(x^2)+2) u čvorovima 1,2,3.
# Nacrtajte graf funkcije i Newtonov polinom i označite čvorove.
# Izračunati apsolutnu i relativnu pogrešku u čvoru 1.8.

import numpy as np
from matplotlib import pyplot


def f(x):
    return x / (np.cos(x**2) + 2)


matrica = np.zeros([3, 3])
x = np.array([1, 2, 3])

matrica[0, 0] = f(x[0])
matrica[1, 0] = f(x[1])
matrica[2, 0] = f(x[2])

matrica[0, 1] = (matrica[1, 0] - matrica[0, 0]) / (x[1] - x[0])
matrica[1, 1] = (matrica[2, 0] - matrica[1, 0]) / (x[2] - x[1])

matrica[0, 2] = (matrica[1, 1] - matrica[0, 1]) / (x[2] - x[0])


def newton(cvor):
    return matrica[0, 0] + (cvor - x[0])*matrica[0, 1] + (cvor - x[0])*(cvor - x[1])*matrica[0, 2]


f_pravo = f(1.8)
f_approx = newton(1.8)
f_approx_absgr = abs(f_pravo - f_approx)
f_approx_relgr = f_approx_absgr/abs(f_pravo)

print(f"Vrijednost u x = 1.8: {f_pravo:.2f}, aproksimacija: {f_approx:.2f}")
print(
    f"Apsolutna pogreska = {f_approx_absgr:.2f}, relativna pogreska = {f_approx_relgr * 100:.2f}%")

domena = np.linspace(0, 4, 100)
pyplot.plot(domena, f(domena), 'r', label="f(x)")
pyplot.plot(domena, newton(domena), 'b', label="newton(x)")
pyplot.plot(x, f(x), 'o', label="cvorovi")
pyplot.legend()
pyplot.show()
