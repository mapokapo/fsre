'''
Leo Petrović 695/RM

10. Za danu listu stringova vrati broj stringova iz liste kojima je duljina >=3 i koji imaju barem dva znaka jednaka prvom znaku.
Npr. za listu ['abc', 'aba', 'cc', 'ijki'] će vratiti 2 (aba i ijki)
'''

words = input("Unesite recenicu: ").split()

filtered = [w for w in words if len(w) >= 3]
filtered = [w for w in filtered if w.count(w[0]) >= 2]

print(f"Filtrirane rijeci: {filtered} (duljina {len(filtered)})")
