# Rjesenje zadanog sustava iznosi x = [1, 1]:
# A = [[0.434, 0.26], [0.79, 0.473]]
# b = [0.694, 1.263]
# a) Promijenite vektor b za [0.00006, 0.000003] i izracunajte uvjetovanost inf A. Koliko je puta relativna greška u rješenju sustava uz promjenu vektora b veća od relativne greške u vektoru b?
# b) Promijenite matricu A za [[-0.001, 0], [0, 0]] i izracunajte uvjetovanost inf A. Koliko je puta relativna greška u rješenju sustava uz promjenu matrice A veća od relativne greške u matrici A?

from math import inf

import numpy as np

A = np.array([
    [0.434, 0.26],
    [0.79, 0.473]
])
b = np.array([0.694, 1.263])
x = np.array([1, 1])

# a)
delta_b = np.array([0.00006, 0.000003])

uvjetovanost_A = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost (inf) A = {uvjetovanost_A:.2f}")

x_novo = np.linalg.solve(A, b + delta_b)

x_rel_greska = np.linalg.norm(x - x_novo, inf) / np.linalg.norm(x, inf)
b_rel_greska = np.linalg.norm(delta_b, inf) / np.linalg.norm(b, inf)

print(f"Greska u rjesenju uz promjenu vektora b = {x_rel_greska * 100:.2f}%")
print(f"Greska u vektoru b = {b_rel_greska * 100:.6f}%")
print(
    f"Greska u rjesenju je veca od greske u vektoru b za {x_rel_greska / b_rel_greska:.2f}x puta")

# b)
delta_A = np.array([[-0.001, 0], [0, 0]])

uvjetovanost_A = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost (inf) A = {uvjetovanost_A:.2f}")

x_novo = np.linalg.solve(A + delta_A, b)

x_rel_greska = np.linalg.norm(x - x_novo, inf) / np.linalg.norm(x, inf)
A_rel_greska = np.linalg.norm(delta_A, inf) / np.linalg.norm(A, inf)

print(f"Greska u rjesenju uz promjenu matrice A = {x_rel_greska * 100:.2f}%")
print(f"Greska u matrici A = {A_rel_greska * 100:.6f}%")
print(
    f"Greska u rjesenju je veca od greske u matrici A za {x_rel_greska / A_rel_greska:.2f}x puta")
