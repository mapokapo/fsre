'''
Leo Petrović 695/RM

8. Za danu listu stringova, vrati rječnik čiji će ključevi biti znakovi iz stringova, a vrijednosti
lista stringova koji sadrže taj znak po redoslijedu pojavljivanja u originalnom stringu.
Napravite vlastitu funkciju.
Npr. za listu ['dobar','dan'] će se dobiti rječnik
 {'d': ['dobar', 'dan'], 'o': ['dobar'],'b':['dobar'],'a':['dobar', 'dan'], 'r': ['dobar'], 'n': ['dan']}
'''

rjecnik: dict[str, list[str]] = {}

words = input("Unesite recenicu: ").split()

for word in words:
    for char in word:
        if char in rjecnik:
            rjecnik[char].append(word)
        else:
            rjecnik[char] = [word]

print(rjecnik)
