# Na intervalu [−π, π] linearnim i kubičnim splajnom interpolirajte funkciju f(x) = xsin(x^2) pomoću 20 čvorova. Nacrtajte graf funkcije i splajn i označite čvorove. Izračunajte apsolutnu pogrešku u čvoru 0.65.

from math import pi

import numpy as np
import scipy
from matplotlib import pyplot


def f(x):
    return x * np.sin(x**2)


cvorovi = np.linspace(-pi, pi, 20)
spline_linear = scipy.interpolate.interp1d(cvorovi, f(cvorovi), kind="linear")
spline_cubic = scipy.interpolate.interp1d(cvorovi, f(cvorovi), kind="cubic")

absgr_linear = abs(f(0.65) - spline_linear(0.65))
relgr_linear = absgr_linear/abs(f(0.65))

absgr_cubic = abs(f(0.65) - spline_cubic(0.65))
relgr_cubic = absgr_cubic/abs(f(0.65))

print(
    f"Linear spline absgr = {absgr_linear}, relgr = {relgr_linear * 100:.2f}%")
print(f"Cubic spline absgr = {absgr_cubic}, relgr = {relgr_cubic * 100:.2f}%")

domena = np.linspace(-pi, pi, 100)
pyplot.plot(domena, f(domena), 'r', label="f(x)")
pyplot.plot(domena, spline_linear(domena), 'g', label="SL(x)")
pyplot.plot(domena, spline_cubic(domena), 'b', label="SC(x)")
pyplot.plot(cvorovi, f(cvorovi), 'o')
pyplot.legend()
pyplot.show()
