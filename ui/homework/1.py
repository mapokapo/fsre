'''
Leo Petrović 695/RM

1. Napisi program koji ispisuje cjelobrojne elemente koji se pojavljuju 3 ili vise puta unutar liste.
Generiraj listu od 100 elemenata u rasponu vrijednosti od 0 do 30.

Primjer ulaza: [4, 6, 6, 6, 3, 8, 21, 21,21, 7, ...]
Izlaz: 6, 21
'''

from random import randint

numbers = [randint(0, 30) for _ in range(100)]

output: list[int] = []
for n in numbers:
    count = 0
    for m in numbers:
        if n == m:
            count += 1

    if count >= 3:
        output.append(n)

print(f"Brojevi: {numbers}")
print(f"Brojevi koji se ponavljaju 3+ puta: {output}")
