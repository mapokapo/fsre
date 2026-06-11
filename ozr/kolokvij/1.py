'''
Izračunajte relativnu pogrešku pri izračunavanju vrijednosti funkcije f(x,y,z)=x3yz−−√
 za

x=2.5±0.01


y=3±0.02


z=4.25±0.05
'''

import numpy as np

def f(x, y, z):
  return x**3 * np.sqrt(y * z)

x = 2.5
x_absgr = 0.01

y = 3
y_absgr = 0.02

z = 4.25
z_absgr = 0.05

def fx(x, y, z):
  return 3*x**2 * np.sqrt(y * z)

def fy(x, y, z):
  return (x**3 * np.sqrt(z)) / (2 * np.sqrt(y))

def fz(x, y, z):
  return (x**3 * np.sqrt(y)) / (2 * np.sqrt(z))


f_pravo = f(x, y, z)
f_abs_greska = abs(fx(x, y, z))*x_absgr + abs(fy(x, y, z))*y_absgr + abs(fz(x, y, z))*z_absgr
f_rel_greska = f_abs_greska/abs(f_pravo)

print(
    f"Prava vrijednost = {f_pravo}, apsolutna greska = {f_abs_greska}, relativna greska = {f_rel_greska * 100:.2f}%")