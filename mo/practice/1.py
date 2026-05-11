# Tvornica proizvodi 4 proizvoda: A, B, C, D
# Varijable: x1, x2, x3, x4 = dnevna kolicina proizvedenih proizvoda A, B, C, D
# Cilj je maksimizirati profit
# Dobit po jedinici proizvoda: 20, 12, 40, 25
# Ukupan broj proizvedenih jedinica ne moze biti veci od 50: x1 + x2 + x3 + x4 <= 50
# Imamo 2 sirovine: A i b
# Jedinica proizvoda A trosi 3 jedinice sirovine A, jedinica B trosi 2 A i 1 B, jedinica C trosi 1 A i 2 B, i jedinica D trosi 3 B.
# Moze se max. proizvesti 100 jedinica sirovine A i 90 jedinica sirovine B dnevno
# U drugim rijecima, npr. za proizvod A: 1 jedinica proizvoda A kosta 3 jedinice sirovine A -> x1 = 3*S_A
# Za preostale proizvode: x2 = 2*S_A + 1*S_B, x3 = 1*S_A + 2*S_B, x4 = 3*S_B
# Ako mozemo proizvesti max. 100 jedinica sirovine A: 3x1 + 2x2 + x3 <= 100
# Isto za sirovinu B: x2 + 2x3 + 3x4 <= 90

import numpy as np
from scipy.optimize import linprog

print("I. Varijable")
print("\tx1 = broj jedinica proizvoda A")
print("\tx2 = broj jedinica proizvoda B")
print("\tx3 = broj jedinica proizvoda C")
print("\tx4 = broj jedinica proizvoda D")

print("\nII. Granice")
print("\t1. x1 + x2 + x3 + x4 <= 50")
print("\t2. 3x1 + 2x2 + x3 <= 100")
print("\t3. x2 + 2x3 + 3x4 <= 90")
print("\tx1, x2, x3, x4 >= 0")

print("\nIII. Funkcija cilja")
print("\tZ = 20x1 + 12x2 + 40x3 + 25x4")

print("\nIV. Matematicki model")
print("\tMax Z = 20x1 + 12x2 + 40x3 + 25x4 + 0u1 + 0u2 + 0u3")
print("\t          x1 +   x2 +   x3 +   x4 +  u1             = 50")
print("\t         3x1 +  2x2 +   x3              +  u2       = 100")
print("\t                 x2 +  2x3 +  3x4             +  u3 = 90")

koeficijenti = np.array([-20, -12, -40, -25])
lijeva_strana_nejednakosti_koeficijenti = np.array([
    [1, 1, 1, 1],
    [3, 2, 1, 0],
    [0, 1, 2, 3]
])
desna_strana_nejednakosti_koeficijenti = np.array([50, 100, 90])

x0_granice = (0, None)
x1_granice = (0, None)
x2_granice = (0, None)
x3_granice = (0, None)

result = linprog(koeficijenti, A_ub=lijeva_strana_nejednakosti_koeficijenti, b_ub=desna_strana_nejednakosti_koeficijenti, bounds=[
                 x0_granice, x1_granice, x2_granice, x3_granice])

if result.x is None or result.fun is None:
    print("\nNije pronadjeno rjesenje!")
    exit(1)

print("\nV. Optimalne vrijednosti")
print(f"\tx1 = {result.x[0]}")
print(f"\tx2 = {result.x[1]}")
print(f"\tx3 = {result.x[2]}")
print(f"\tx4 = {result.x[3]}")
print(f"\tMax Z = {-result.fun}")
