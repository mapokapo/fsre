'''
Leo Petrović 695/RM

9. Za danu matricu stringova pronađi elemente koji nisu brojcani stringovi i vrati rječnik čiji će ključ biti njihovih pozicija, a vrijednost sam element.
Pozicija je predstavljena kao uređeni par (x,y) gdje je x broj reda, a y broj stupca elementa koji nije broj.
Napravite vlastitu funkciju.
Napomena: prvi redak i prvi stupac imaju poziciju 0. Npr. za matricu
    5 4 a 1
    c 3 12 b
    7 9 0 d
se dobiva {(0,2): 'a', (1,0): 'c', (1,3): 'b', (2,3): 'd'} 
'''


def is_integer(s: str) -> bool:
    try:
        int(s)
        return True
    except ValueError:
        return False


matrix: list[list[str]] = []

while True:
    text = input(
        "Unesite vrijednosti reda odvojene razmakom (ili pritisnite ENTER za kraj): ")
    if len(text.strip()) == 0:
        break

    row_values = text.split()
    matrix.append(row_values)


output: dict[tuple[int, int], str] = {}
for row_index, row in enumerate(matrix):
    for col_index, cell in enumerate(row):
        if not is_integer(cell):
            output[(row_index, col_index)] = cell

print(f"Pozicije ne-brojcanih stringova: {output}")
