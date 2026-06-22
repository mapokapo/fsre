# Ispitaj jesu li sustavi dobro ili lose uvjetovani:
# a)
# x + y = 2
# x + 1.001y = 2
# b)
# x + y = 2
# -x + 2y = 2
# U oba slucaja, izracunati rjesenje i za b = [2, 2.001]

# a)
from math import inf

import numpy as np

A = np.array([
    [1, 1],
    [1, 1.001]
])
b = np.array([2, 2])

uvjetovanost_a = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)

print(f"Uvjetovanost = {uvjetovanost_a:.2f}")

# provjera

rjesenje_a = np.linalg.solve(A, b)
print(f"Rjesenje = {rjesenje_a}")

delta_b = np.array([0, 0.001])

rjesenje_novo_a = np.linalg.solve(A, b + delta_b)
print(f"Rjesenje nakon male promjene b = {rjesenje_novo_a}")

rjesenje_novo_a_rel_greska = np.linalg.norm(
    rjesenje_a - rjesenje_novo_a) / np.linalg.norm(rjesenje_a)
print(f"Relativna greska rjesenja = {rjesenje_novo_a_rel_greska * 100:.2f}%")

# b)

A = np.array([
    [1, 1],
    [-1, 2]
])

uvjetovanost_b = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)

print(f"Uvjetovanost = {uvjetovanost_b:.2f}")

# provjera

rjesenje_b = np.linalg.solve(A, b)
print(f"Rjesenje = {rjesenje_b}")

rjesenje_novo_b = np.linalg.solve(A, b + delta_b)
print(f"Rjesenje nakon male promjene b = {rjesenje_novo_b}")

rjesenje_novo_b_rel_greska = np.linalg.norm(
    rjesenje_b - rjesenje_novo_b) / np.linalg.norm(rjesenje_a)
print(f"Relativna greska rjesenja = {rjesenje_novo_b_rel_greska * 100:.6f}%")
