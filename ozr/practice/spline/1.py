# Konstruirajte linearni splajn na 15 podintervala od -π/2 do π/2 za funkciju f(x) = cos(x) + sin(3x).
# Nacrtajte splajn i graf funkcije, te izračunajte rel pogrešku u čvoru 1.5.

from math import pi

import numpy as np
from matplotlib import pyplot
from scipy import interpolate as i


def f(x):
    return np.cos(x) + np.sin(3 * x)


domena = np.linspace(-pi/2, pi/2, 16)

inter = i.interp1d(domena, f(domena), kind="linear")

absgr = abs(f(1.5) - inter(1.5))
relgr = absgr/abs(f(1.5))

print(f"absgr = {absgr}, relgr = {relgr * 100:.2f}%")

x_os = np.linspace(-pi/2, pi/2, 100)
pyplot.plot(x_os, f(x_os), 'r')
pyplot.plot(x_os, inter(x_os), 'r')
pyplot.show()
