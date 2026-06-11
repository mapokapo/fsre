# Nacrtajte grafove Lagrangeovih baza za čvorove 0, 2, 3.

import numpy as np
from matplotlib import pyplot


def l0(x, x0, x1, x2):
    return (x - x1)*(x - x2)/((x0 - x1)*(x0 - x2))


def l1(x, x0, x1, x2):
    return (x - x0)*(x - x2)/((x1 - x0)*(x1 - x2))


def l2(x, x0, x1, x2):
    return (x - x0)*(x - x1)/((x2 - x0)*(x2 - x1))


domena = np.linspace(-5, 5, 100)

pyplot.plot(domena, l0(domena, 0, 2, 3))
pyplot.plot(domena, l1(domena, 0, 2, 3))
pyplot.plot(domena, l2(domena, 0, 2, 3))
pyplot.show()
