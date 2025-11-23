'''
Leo Petrović 695/RM

3. Napisi program i funkciju loto642 koja simulira loto 6/42.

a) Funkcija izvlaci 6 brojeva te jedan dopunski broj preko generatora slučajnih brojeva. Funkcija vraća listu loto brojeva.
b) Brojeve igrača možete unijeti prilikom inicijalizacije liste (ručno).
c) Potrebno je odrediti ukupan broj pogodaka pri izvlačenju i ispisati na ekran.
d) Odrediti sumu pogođenih, minimum i maksimalni pogođeni broj. 
'''

import random


def loto642():
    picked_numbers = set(random.sample(range(1, 42), 7))
    bonus_number = picked_numbers.pop()

    return (picked_numbers, bonus_number)


guessed = {int(n.strip())
           for n in input("Unesite 6 brojeva (npr. 1,2,3,4,5,6): ").split(",")}
(picked, bonus) = loto642()
correct = (picked | {bonus}) & guessed

print(f"Vasi brojevi: {guessed}")
print(f"Izvuceni brojevi: {picked} (+bonus: {bonus})")

if len(correct) == 0:
    print("Niste pogodili nijedan broj!")
    exit()

print(f"Pogodjeni brojevi: {correct} ({len(correct)})")
print(f"Pogodjen bonus: {"DA" if bonus in guessed else "NE"}")
print(f"Suma pogodjenih brojeva: {sum(correct)}")
print(f"Najmanji pogodjeni broj: {min(correct)}")
print(f"Najveci pogodjeni broj: {max(correct)}")
