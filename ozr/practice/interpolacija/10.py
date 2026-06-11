# Aproksimirajte funkciju f(x) = 1/(x^2 + 1) na intervalu [0, 5] upotrebom 5, 10, 20 čvorova. Izračunajte relativnu pogrešku u čvoru 0.6.

import numpy as np
import scipy


def f(x):
    return 1 / (x ** 2 + 1)


for n in [5, 10, 20]:
    domena = np.linspace(0, 5, n)
    LB = scipy.interpolate.BarycentricInterpolator(domena, f(domena))
    f_prava = f(0.6)
    f_approx = LB(0.6)
    f_absgr = abs(f_prava - f_approx)
    f_relgr = f_absgr/abs(f_prava)
    print(f"[{n} cvorova] Vrijednost = {f_prava}, approx = {f_approx}, absgr = {f_absgr}, relgr = {f_relgr * 100:.2f}%")
