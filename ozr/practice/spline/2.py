# Kubičnim splajnom aproksimirajte funkciju f(x) = x/(x^4 + 1) na 5 podintervala.
# Nacrtajte splajn i graf funkcije. Te izračunajte relativnu pogrešku u čvoru 0.5.

import numpy as np
import scipy
from matplotlib import pyplot


def f(x):
    return x / (x**4 + 1)


intervali = np.linspace(-5, 5, 6)

spline = scipy.interpolate.interp1d(intervali, f(intervali), kind="cubic")

absgr = abs(f(0.5) - spline(0.5))
relgr = absgr/abs(f(0.5))

print(f"absgr = {absgr}, relgr = {relgr * 100:.2f}%")

domena = np.linspace(-5, 5, 100)
pyplot.plot(domena, f(domena), label="f(x)")
pyplot.plot(domena, spline(domena), label="spline(x)")
pyplot.plot(intervali, f(intervali), 'o')
pyplot.legend()
pyplot.show()
