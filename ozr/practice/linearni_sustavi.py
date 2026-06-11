'''
1. Ispitajte da li je sustav linearnih jednadžbi dobro ili loše uvjetovan:
  a) x + y = 2
     x + 1.001y = 2
  b) x + y = 2
    -x + 2y = 2
U oba primjera, izracunajte rješenje i za b=[2, 2.001].
'''

from math import inf

import numpy as np

print("### LINEARNI SUSTAVI ###")
print()
print("1. Zadatak")


# a)
A = np.array([
    [1, 1],
    [1, 1.001]
])
b = np.array([
    2,
    2
])

uvjetovanost = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost = {uvjetovanost:.6f}")

x = np.linalg.solve(A, b)
print(f"Rjesenje = {x}")

novo_b = np.array([2, 2.001])

x = np.linalg.solve(A, novo_b)
print(f"Novo rjesenje = {x}")

# b)
A = np.array([  # pyright: ignore[reportConstantRedefinition]
    [1, 1],
    [-1, 2]
])
b = np.array([
    2,
    2
])

uvjetovanost = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost = {uvjetovanost:.6f}")

x = np.linalg.solve(A, b)
print(f"Rjesenje = {x}")

novo_b = np.array([2, 2.001])

x = np.linalg.solve(A, novo_b)
print(f"Novo rjesenje = {x}")

'''
2. Ispitajte uvjetovanost matrice
[[ 2  0  0 ]
 [ 0 -3  3 ]
 [ 0  3  5 ]]
u 2 i inf normi.
'''

print()
print("2. Zadatak")

matrica = np.array([
    [2, 0, 0],
    [0, -3, 3],
    [0, 3, 5]
])

uvjetovanost = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost (inf) = {uvjetovanost:.6f}")

uvjetovanost = np.linalg.norm(A, 2) * np.linalg.norm(np.linalg.inv(A), 2)
print(f"Uvjetovanost (2) = {uvjetovanost:.6f}")

'''
3. Rješenje sustava gdje su matrica sustava A i vektor b dani sa:
A = [[ 0.434 0.26 ]
     [ 0.79  0.473 ]]
b = [0.694 1.263]

iznosi x = [1, 1].

a) Promijenite vektor b za ∆𝑏 = [0.00006, 0.000003]. Izračunajte inf uvjetovanost matrice A. Koliko je puta relativna greška u rješenju sustava uz promjenu vektora b veća od relativne greške u vektoru b?

b) Promijenite matricu A za ∆A = [[-0.001, 0], [0, 0]]. Izračunajte inf uvjetovanost matrice A. Koliko je puta relativna greška u rješenju sustava uz promjenu matrice A veća od relativne greške u matrici A?
'''

print()
print("3. Zadatak")

A = np.array([  # pyright: ignore[reportConstantRedefinition]
    [0.434, 0.26],
    [0.79, 0.473]
])
b = np.array([0.694, 1.263])
x_pravo = np.array([1, 1])

# a)
delta_b = np.array([0.00006, 0.000003])

rjesenje = np.linalg.solve(A, b + delta_b)

uvjetovanost = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost matrice A = {uvjetovanost:.6f}")

x_rel_greska = np.linalg.norm(
    rjesenje - x_pravo, inf) / np.linalg.norm(x_pravo, inf)
novo_b_rel_greska = np.linalg.norm(delta_b, inf) / np.linalg.norm(b, inf)

print(f"Relativna greska rjesenja = {x_rel_greska * 100:.2f}%, relativna greska novog b = {novo_b_rel_greska * 100:.6f}%, relativna greska rjesenja je od novog b veca za {(x_rel_greska / novo_b_rel_greska):.2f}x puta")

# b)
delta_A = np.array([
    [-0.001, 0],
    [0, 0]
])

rjesenje = np.linalg.solve(A + delta_A, b)

uvjetovanost = np.linalg.norm(A, inf) * np.linalg.norm(np.linalg.inv(A), inf)
print(f"Uvjetovanost matrice A = {uvjetovanost:.6f}")

x_rel_greska = np.linalg.norm(
    rjesenje - x_pravo, inf) / np.linalg.norm(x_pravo, inf)
novo_A_rel_greska = np.linalg.norm(delta_A, inf) / np.linalg.norm(A, inf)

print(f"Relativna greska rjesenja = {x_rel_greska * 100:.2f}%, relativna greska novog A = {novo_A_rel_greska * 100:.6f}%, relativna greska rjesenja je od novog A veca za {(x_rel_greska / novo_A_rel_greska):.2f}x puta")

'''
4. LU dekompozicijom riješi sustav koji je zadan sa:
a) A = [[1  2  3]
        [0  2  2]
        [3  2 -1]]
b = [2 3 1]

b) A = [[1  2  3]
        [0  2  2]
        [3  2 -1]] (ista matrica)
b = [-1 5 2]
'''

print()
print("4. Zadatak")

import scipy  # noqa: E402

# a)
A = np.array([  # pyright: ignore[reportConstantRedefinition]
    [1, 2, 3],
    [0, 2, 2],
    [3, 2, -1]
])
b = np.array([2, 3, 1])

P, L, U = scipy.linalg.lu(A)

y = np.linalg.solve(L, np.dot(P, b))
x = np.linalg.solve(U, y)
print(f"Rjesenje: {x}")

# b)
b = np.array([-1, 5, 2])

y = np.linalg.solve(L, np.dot(P, b))
x = np.linalg.solve(U, y)
print(f"Rjesenje: {x}")

'''
5. LU dekompozicijom riješi sustav koji je zadan sa:
a) A = [[0  7  8]
        [0  2  1]
        [3  0 -1]]
b = [2 3 1]

b) A = [[0  7  8]
        [0  2  1]
        [3  0 -1]] (ista matrica)
b = [-1 5 2]
'''

print()
print("5. Zadatak")

# a)
A = np.array([  # pyright: ignore[reportConstantRedefinition]
    [0, 7, 8],
    [0, 2, 1],
    [3, 0, -1]
])
b = np.array([2, 3, 1])

P, L, U = scipy.linalg.lu(A)  # pyright: ignore[reportConstantRedefinition]

y = np.linalg.solve(L, np.dot(P, b))
x = np.linalg.solve(U, y)
print(f"Rjesenje: {x}")

# b)
b = np.array([-1, 5, 2])

y = np.linalg.solve(L, np.dot(P, b))
x = np.linalg.solve(U, y)
print(f"Rjesenje: {x}")
