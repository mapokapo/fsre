'''
Leo Petrović 695/RM

5. Robot se kreće po točkama pravokutnog koordinatnog sustava u ravnini, počevši od točke (5, 7).
Zadana je njegova putanja kao string sastavljen od znakova (npr: "SJIJI"):
- S (idi sjeverno)
- J (idi južno)
- I (idi istočno)
- Z (idi zapadno)

Ako korisnik unese S robot će ići na Sjever za 3 točke, a za sve ostale će ići po jednu
točku. Na primjer, ako je robot u točki (0, 0) nakon naredbe Z putuje u točku (-1, 0), a
nakon S putuje u točku (0, 3). Napišite program koji određuje konačnu poziciju robota za
proizvoljan broj točaka.
'''

position = (5, 7)


def get_delta(dir: str) -> tuple[int, int]:
    match dir.lower():
        case 's':
            return (0, 3)
        case 'i':
            return (1, 0)
        case 'j':
            return (0, -1)
        case 'z':
            return (-1, 0)
        case _:
            return (0, 0)


print(f"Robot je na poziciji {position}")
print("""Dostupne instrukcije:
 - S = 3 koraka prema sjeveru
 - I = 1 korak prema istoku
 - J = 1 korak prema jugu
 - Z = 1 korak prema zapadu""")

directions = list(input("Unesite instrukcije (npr. 'SJIJI'): "))
directions = [get_delta(dir) for dir in directions]

for dir in directions:
    position = (position[0] + dir[0], position[1] + dir[1])

print(f"Robot je sada na poziciji {position}")
