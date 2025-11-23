'''
Leo Petrović 695/RM

7. Zadan je rječnik čiji su ključevi imena studenata, a vrijednosti ocjene. Vrijednosti trebaju biti u obliku ntorke.
Potrebno je vratiti rječnik čiji će ključevi biti prosječna ocjena (zaokružena - koristiti round() funkciju), a vrijednosti sortirana lista studenata koji su dobili tu prosječnu ocjenu.
Npr. u rječniku {'ivan': (3,2,4), 'marko': (5,3,4), 'ana': (2,3,4)}, 'ivan' ima ocjene 3, 2, 4 i
prosječna ocjena je 3.0, 'marko' ima ocjene 5, 3, 4 i prosječna ocjena je 4.0, 'ana' ima
ocjene 2, 3, 4 i prosječna ocjena je 3.0.
 Izlazni rječnik će biti {3: ['ana', 'ivan'], 4: ['marko']} jer 'ivan' i 'ana' imaju prosjek 3.0, a
'marko' prosjek 4.
'''

studenti: dict[str, tuple[int, ...]] = {}
while True:
    next = input("Zelite li unijeti studenta? [Y/n] ")
    if next.lower() == "n":
        break

    name = input("Unesite ime studenta: ")
    grades = tuple(int(n) for n in input(
        "Unesite ocjene studenta (npr. '1,2,3,4,5'): ").split(","))

    studenti[name] = grades

ocjene: dict[float, list[str]] = {}
for (name, grades) in studenti.items():
    average_grade = sum(grades) / len(grades)

    if average_grade in ocjene:
        ocjene[average_grade].append(name)
    else:
        ocjene[average_grade] = [name]

print(f"Prosjecne ocjene: {ocjene}")
