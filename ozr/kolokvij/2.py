'''
Newtonovim polinomom interpolirajte funkciju f(x)=(e^(x^2))/(x^2 + 1) u čvorovim 0,1,2.
Nacrtajte graf funkcije i Newtonov polinom i označite čvorove.
Izračunajte apsolutnu i relativnu pogrešku u čvoru 0.35.
'''

import numpy as np
from matplotlib import pyplot


def f(x):
    return np.exp(x ** 2) / (x ** 2 + 1)


matrica = np.zeros([3, 3])
cvorovi = np.array([0, 1, 2])

matrica[0, 0] = f(cvorovi[0])
matrica[1, 0] = f(cvorovi[1])
matrica[2, 0] = f(cvorovi[2])

matrica[0, 1] = (matrica[1, 0] - matrica[0, 0]) / (cvorovi[1] - cvorovi[0])
matrica[1, 1] = (matrica[2, 0] - matrica[1, 0]) / (cvorovi[2] - cvorovi[1])

matrica[0, 2] = (matrica[1, 1] - matrica[0, 1]) / (cvorovi[2] - cvorovi[0])


def newton(x):
    return matrica[0, 0] + (x - cvorovi[0])*matrica[0, 1] + (x - cvorovi[0])*(x - cvorovi[1])*matrica[0, 2]


f_pravo = f(0.35)
f_newton = newton(0.35)
f_newton_absgr = abs(f_pravo - f_newton)
f_newton_relgr = f_newton_absgr/abs(f_pravo)

print(f"Vrijednost u x = 0.35: {f_pravo:.2f}, newton: {f_newton:.2f}")
print(
    f"Apsolutna greska = {f_newton_absgr:.2f}, relativna greska = {f_newton_relgr * 100:.2f}%")

domena = np.linspace(-1, 3, 100)
pyplot.plot(domena, f(domena), 'r', label="f(x)")
pyplot.plot(domena, newton(domena), 'b', label="newton(x)")
pyplot.plot(cvorovi, f(cvorovi), 'o', label="cvorovi")
pyplot.legend()
pyplot.show()
