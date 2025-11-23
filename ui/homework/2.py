'''
Leo Petrović 695/RM

2. Napisi Python funkciju koja filtrira vrijednosti rjecnika na osnovu visine i kao rezultat daje novi rjecnik.
Argumenti funkcije trebaju biti rjecnik, i visina po kojoj se filtrira.
(primjer: filtrira sve osobe koje su vece od odredene visine)

Rjecnik:
{'Pero Peric': 175, 'Marko Markic': 180, 'Jure Juric': 165, 'Marija Maric': 190} 
'''

rjecnik = {'Pero Peric': 175, 'Marko Markic': 180,
           'Jure Juric': 165, 'Marija Maric': 190}


def filtriraj_rjecnik(ulaz: dict[str, int], min_visina: int) -> dict[str, int]:
    izlaz: dict[str, int] = {}

    for (k, v) in ulaz.items():
        if v > min_visina:
            izlaz[k] = v

    return izlaz


print(f"Rjecnik: {rjecnik}")

min_visina = int(input("Unesite minimalnu visinu: "))

print(f"Filtrirani rjecnik: {filtriraj_rjecnik(rjecnik, min_visina)}")
