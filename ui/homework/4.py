'''
Leo Petrović 695/RM

4. Kreirati listu prirodnih brojeva od 50 elemenata (koristiti random funkciju).
Za danu listu prirodnih brojeva stvori rječnik u kojemu će se nalaziti frekvencija pojavljivanja određene brojčane znamenke u svim brojevima iz liste. Npr. za [423, 54, 45] broj 4 se pojavljuje 3 puta, 2 - 1 put, 3 -1 put, itd.
Napomena: ključevi rječnika neka budu brojevi, a ne stringovi. 
'''

from random import randint

frekvencije = {
    0: 0,
    1: 0,
    2: 0,
    3: 0,
    4: 0,
    5: 0,
    6: 0,
    7: 0,
    8: 0,
    9: 0
}

random_numbers = [randint(0, 1000) for _ in range(50)]

for n in random_numbers:
    digits = [int(d) for d in str(n)]

    for d in digits:
        frekvencije[d] += 1


print("Frekvencije pojavljivanja znamenki 0-9:")
print("\n".join([f"\t{k} = {v}" for (k, v) in frekvencije.items()]))
