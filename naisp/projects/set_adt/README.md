# Set ADT s vise implementacija

Ovo je studentski primjer generickog apstraktnog tipa podataka Set u C-u. Sve implementacije koriste isti javni API iz `set.h`, a konkretna implementacija bira se u runtime-u preko `SetType`.

## Build i pokretanje

```sh
make
make run
make valgrind
```

## Datoteke

- `set.h` - javno sucelje ADT-a.
- `set.c` - implementacije: nesortirano polje, sortirano polje, povezana lista, hash tablica i BST.
- `main.c` - demo/test program za sve operacije i vise tipova podataka.
- `Makefile` - jednostavno prevodenje i pokretanje.

## API

Glavne funkcije:

- `set_create`, `set_destroy`
- `set_insert`
- `set_remove`
- `set_contains`
- `set_size`
- `set_union`
- `set_intersection`
- `set_difference`

Korisnik predaje funkcije za usporedbu, hashiranje, kopiranje i oslobadanje elemenata. Kopiranje nije strogo obavezno, ali je preporuceno jer tada skup ima vlastite kopije podataka i rezultati operacija poput unije i presjeka mogu se sigurno osloboditi bez dvostrukog `free`.

## Implementacije

### Nesortirano polje

Elementi se spremaju redom umetanja. Implementacija je najjednostavnija, ali pretrazivanje je linearno.

- `contains`: O(n)
- `insert`: O(n), jer se prvo provjerava postoji li element
- `remove`: O(n)

Prednost je jednostavnost i dobro ponasanje za male skupove. Nedostatak je sporo pretrazivanje kod vecih skupova.

### Sortirano polje

Elementi se odrzavaju sortirani. Pretrazivanje koristi binarno pretrazivanje, ali umetanje i brisanje mogu pomicati elemente.

- `contains`: O(log n)
- `insert`: O(n)
- `remove`: O(n)

Dobro je kada ima puno pretrazivanja, a malo umetanja i brisanja.

### Povezana lista

Elementi su u jednostruko povezanoj listi. Umetanje je jednostavno, ali pronalazak duplikata je linearan.

- `contains`: O(n)
- `insert`: O(n)
- `remove`: O(n)

Prednost je jednostavna dinamicka memorija bez realokacije polja. Nedostatak je losija cache lokalnost i linearno pretrazivanje.

### Hash tablica

Koristi hash tablicu s ulanacavanjem. Korisnik mora predati hash funkciju.

- `contains`: prosjecno O(1), najgore O(n)
- `insert`: prosjecno O(1), najgore O(n)
- `remove`: prosjecno O(1), najgore O(n)

Najbolji izbor za ceste operacije umetanja, brisanja i pretrazivanja ako postoji dobra hash funkcija.

### Binarno stablo pretrazivanja

Koristi obicni BST bez balansiranja.

- `contains`: prosjecno O(log n), najgore O(n)
- `insert`: prosjecno O(log n), najgore O(n)
- `remove`: prosjecno O(log n), najgore O(n)

Prednost je sortirani obilazak. Nedostatak je sto se bez balansiranja moze degenerirati u listu.

## Operacije nad skupovima

`set_union`, `set_intersection` i `set_difference` rade preko javnog ponasanja ADT-a, neovisno o konkretnoj implementaciji. Rezultirajuci skup koristi istu implementaciju kao prvi operand.

## Testiranje

`main.c` pokrece iste operacije nad svih pet implementacija:

- umetanje elemenata i ignoriranje duplikata
- `contains`
- `remove`
- `union`
- `intersection`
- `difference`

Demo dodatno pokazuje rad s:

- `int`
- `string`
- korisnickom strukturom `Student`
