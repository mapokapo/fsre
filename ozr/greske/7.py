# Zaokruziti broj pi na 3 decimale te izracunati apsolutnu u relativnu gresku aproksimacije

from math import pi

pi_approx = round(pi, 3)
pi_approx_abs_greska = abs(pi - pi_approx)
pi_approx_rel_greska = pi_approx_abs_greska/abs(pi)

print(f"PI approx = {pi_approx}, apsolutna greska = {pi_approx_abs_greska}, relativna greska = {pi_approx_rel_greska * 100:.2f}%")
