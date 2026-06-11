# Izracunajte sumu niza prvi 10^6 clanova niza a_i = 1/i, i = 1,..., i izracunajte apsolutnu i relativnu gresku za sumu unaprijed i unazad. Referentno rjesenje izracunajte aritmetikom sa povecanom preciznoscu.

from decimal import Decimal, getcontext

getcontext().prec = 50
suma_ref = Decimal(0)

for n in range(1, 10**6 + 1, 1):
    suma_ref += Decimal(1) / Decimal(n)

suma_unaprijed = 0

for n in range(1, 10**6 + 1, 1):
    suma_unaprijed += 1 / n

suma_unazad = 0

for n in range(10**6, 0, -1):
    suma_unazad += 1 / n

suma_unaprijed_abs_greska = abs(float(suma_ref) - suma_unaprijed)
suma_unaprijed_rel_greska = suma_unaprijed_abs_greska/abs(float(suma_ref))

suma_unazad_abs_greska = abs(float(suma_ref) - suma_unazad)
suma_unazad_rel_greska = suma_unazad_abs_greska/abs(float(suma_ref))

print(
    f"Referentna suma = {suma_ref}, suma unaprijed = {suma_unaprijed}, suma unazad = {suma_unazad}")
print(
    f"Apsolutna i relativna greska sume unaprijed = {suma_unaprijed_abs_greska}, {suma_unaprijed_rel_greska * 100}%")
print(
    f"Apsolutna i relativna greska sume unazad = {suma_unazad_abs_greska}, {suma_unazad_rel_greska * 100}%")
