# Projekti: Napredne strukture podataka

---

## Projekt 1: Generički framework za linearne strukture

### Opis

Cilj projekta je implementirati generički framework u programskom jeziku C za osnovne linearne strukture podataka: listu, stog i red. Framework mora omogućiti korištenje istog API-ja neovisno o konkretnoj implementaciji.

### Zahtjevi

Potrebno je implementirati sljedeće strukture:

- Jednostruko povezana lista
- Dvostruko povezana lista
- Stog:
  - implementacija pomoću polja
  - implementacija pomoću liste
- Red:
  - implementacija pomoću kružnog polja
  - implementacija pomoću liste

Sve strukture moraju koristiti generički tip (`void*`) za pohranu podataka.

### API zahtjevi

Definirati jedinstveno sučelje za sve strukture, uključujući:

- inicijalizaciju i deklaraciju
- umetanje i uklanjanje elemenata
- dohvat vrha/početka
- provjeru praznine

Korisnik mora moći proslijediti funkcijske pokazivače za:

- usporedbu elemenata
- ispis elemenata
- oslobađanje memorije

### Dodatni zahtjevi

- Implementirati robusno upravljanje memorijom
- Onemogućiti curenje memorije (valgrind clean)
- Razdvojiti `.h` i `.c` datoteke
- Omogućiti zamjenu implementacije bez promjene korisničkog koda

### Testiranje

Napisati test program koji demonstrira:

- korištenje svih struktura
- rad s različitim tipovima podataka (`int`, `string`, strukture)

### Dodatne napomene

U ovom projektu razvijate modularni i generički framework u C-u koji objedinjuje više linearnih struktura podataka iza jedinstvenog sučelja. Cilj nije samo implementirati strukture, nego dizajnirati apstrakcijski sloj koji omogućuje da se različite implementacije koriste na isti način.

Konkretno, razvijate sustav u kojem korisnik može, primjerice, koristiti stog bez znanja je li implementiran pomoću polja ili povezane liste — jedina razlika smije biti u inicijalizaciji.

#### Što to znači u praksi

Svaka struktura (lista, stog, red) mora:

- imati vlastitu internu implementaciju (`struct` i funkcije)
- ali i zajednički "interfejs" sloj (npr. preko function pointera ili struct-a s metodama)

Primjer ideje (ne rješenje):

- korisnik poziva `stack_push(s, element)`
- implementacija može biti:
  - array-based stack
  - linked-list stack

#### Ključni koncepti koje morate riješiti

- **Generičnost u C-u:**
  - korištenje `void*`
  - izbjegavanje cast grešaka
- **Funkcijski pokazivači:**
  - usporedba (`cmp`)
  - dealokacija (`free_fn`)
  - ispis (`print_fn`)
- **Encapsulation u C-u:**
  - korisnik ne smije direktno pristupati internim strukturama
- **Zamjenjivost implementacije:**
  - ista funkcija → različita implementacija

#### Dizajnerski izazov

Najveći izazov ovog projekta nije implementacija liste ili reda, nego: **kako dizajnirati API da bude čist, konzistentan i proširiv**.

### Očekivani rezultat

- biblioteku (`.h` + `.c`) koju drugi mogu koristiti
- primjer programa koji pokazuje:
  - zamjenu implementacije bez promjene logike
  - rad s različitim tipovima podataka

---

## Projekt 2: Set ADT s više implementacija

### Opis

Cilj projekta je implementirati apstraktni tip podataka Set (skup) s više različitih implementacija koje dijele isti API.

### Implementacije

Potrebno je implementirati Set koristeći:

- nesortirano polje
- sortirano polje
- povezanu listu
- hash tablicu (open addressing ili chaining)
- binarno stablo pretraživanja (BST)

### API zahtjevi

Implementirati sljedeće operacije:

- `set_create`, `set_destroy`
- `set_insert`
- `set_remove`
- `set_contains`
- `set_size`
- `set_union`
- `set_intersection`
- `set_difference`

Sve operacije moraju raditi neovisno o implementaciji.

### Generičnost

- Koristiti `void*`
- Korisnik definira:
  - funkciju usporedbe
  - hash funkciju (za hash implementaciju)

### Dodatni zahtjevi

- Analizirati vremensku složenost svake implementacije
- Omogućiti odabir implementacije u runtime-u ili compile-time-u
- Dokumentirati prednosti i nedostatke svake implementacije

### Testiranje

- Testirati sve operacije nad istim skupom podataka
- Usporediti rezultate između implementacija

### Dodatne napomene

U ovom projektu implementirate apstraktni tip podataka Skup (Set), gdje je ključna ideja da skup:

- ne dopušta duplikate
- nema inherentni redoslijed (ovisno o implementaciji)

Glavni cilj je pokazati kako ista apstrakcija može imati potpuno različite implementacije, s različitim performansama.

#### Ključni problemi koje rješavate

- Detekcija duplikata
- Efikasnost operacija: `contains`, `insert`
- Različiti trade-offovi:
  - hash → brz, ali složen
  - stablo → strukturiran, ali ovisan o balansu
  - polje → jednostavno, ali sporo

#### Posebni zahtjevi

- Za hash implementaciju: morate definirati ili zahtijevati hash funkciju
- Za stablo: koristiti BST (balansiranje je opcionalni bonus)

#### Matematičke operacije

Implementirati operacije nad skupovima: unija, presjek, razlika.

> **Važno:** ove operacije moraju raditi neovisno o implementaciji.

### Očekivani rezultat

- više implementacija istog ADT-a
- jasno definirano sučelje
- analiza: kada koristiti koju implementaciju i zašto

---

## Projekt 3: Graph framework (lista vs matrica susjedstva)

### Opis

Implementirati generički framework za rad s grafovima s više reprezentacija.

### Implementacije

- Matrica susjedstva
- Lista susjedstva

### Podržane funkcionalnosti

Graf mora podržavati:

- usmjereni i neusmjereni graf
- težinski i netežinski graf

### API zahtjevi

- `graph_create`, `graph_destroy`
- `add_vertex`, `remove_vertex`
- `add_edge`, `remove_edge`
- `has_edge`
- `get_neighbors`

### Algoritmi

Implementirati:

- BFS (Breadth-First Search)
- DFS (Depth-First Search)
- pronalazak puta između dva čvora
- provjeru povezanosti grafa

### Dodatni zahtjevi

- Podrška za generičke podatke u čvorovima
- Efikasno upravljanje memorijom
- Mogućnost konverzije između reprezentacija

### Testiranje

- Kreirati test grafove
- Demonstrirati algoritme na primjerima
- Usporediti performanse matrice i liste

### Dodatne napomene

Ovdje implementirate kompleksniju strukturu — graf — i istražujete kako izbor reprezentacije utječe na algoritme.

Vaš graf mora biti dovoljno fleksibilan da podržava:

- usmjerenost (directed / undirected)
- težine bridova
- dinamičko dodavanje čvorova i bridova

#### Algoritamski dio

Implementirati i koristiti BFS, DFS i pronalazak puta između čvorova.

> **Važno:** algoritmi ne smiju ovisiti o implementaciji grafa.

#### Dizajnerski izazov

Kako napisati BFS koji radi i na matrici i na listi bez dupliciranja koda?

### Očekivani rezultat

- fleksibilan graph API
- demonstracija razlika u performansama
- primjeri korištenja (npr. mali social network, mapa, itd.)

---

## Projekt 4: Iterator i kolekcijski framework u C-u

### Opis

Cilj je implementirati generički iterator sustav koji omogućuje uniformno obilazak različitih struktura podataka.

### Podržane strukture

- lista
- stog
- red
- set
- graf (susjedi čvora)

### API iteratora

Definirati apstraktni iterator:

- `iterator_create`
- `iterator_next`
- `iterator_has_next`
- `iterator_destroy`

### Funkcionalni stil

Implementirati generičke funkcije:

- `for_each`
- `map`
- `filter`

### Zahtjevi

- Iterator mora raditi neovisno o strukturi
- Ne smije otkrivati internu implementaciju strukture
- Mora podržavati više aktivnih iteratora

### Dodatni izazovi

- Implementirati "lazy" iteratore
- Omogućiti chaining (`filter` → `map` → `for_each`)

### Testiranje

- Demonstrirati korištenje iteratora nad svim strukturama
- Usporediti kod s i bez iteratora (čitljivost)

### Dodatne napomene

C nema ugrađene iteratore kao moderni jezici, pa je cilj ovog projekta ručno implementirati iterator model.

Cilj je omogućiti korisniku da piše kod poput:

```c
while (iterator_has_next(it)) {
    void* x = iterator_next(it);
}
```

bez obzira radi li se o listi, setu ili grafu.

#### Ključni problemi

- kako sakriti internu strukturu?
- kako omogućiti više iteratora istovremeno?
- kako izbjeći invalidne pokazivače?

#### Napredni dio (bonus)

- lazy evaluacija
- kombiniranje iteratora (pipeline)

### Očekivani rezultat

- univerzalni iterator sustav
- demonstracija na više struktura
- elegantniji kod u odnosu na "ručno" obilazak

---

## Projekt 5: Benchmark i test framework

### Opis

Cilj projekta je razviti sustav za testiranje i usporedbu performansi različitih implementacija struktura podataka.

### Funkcionalnosti

Framework mora omogućiti:

- automatsko pokretanje testova
- mjerenje vremena izvođenja
- mjerenje memorijske potrošnje
- generiranje rezultata

### Strukture za testiranje

Uključiti:

- lista (više implementacija)
- stog
- red
- set
- graf

### Benchmark scenariji

Primjeri:

- umetanje N elemenata
- pretraživanje
- brisanje
- iteracija

### Mjerenja

- vrijeme (npr. `clock_gettime`)
- broj operacija
- memorija (procjena ili alat)

### Izlaz

- tablice rezultata
- opcionalno: CSV za grafove

### Dodatni zahtjevi

- modularan dizajn
- reproducibilni testovi
- konfigurabilni parametri (veličina ulaza)

### Izvještaj

Studenti moraju napisati kratak izvještaj koji uključuje:

- metodologiju testiranja
- interpretaciju rezultata
- usporedbu implementacija

### Dodatne napomene

Ovaj projekt prelazi iz implementacije u inženjerski pristup: ne samo "napraviti strukturu", nego izmjeriti koliko je dobra.

#### Što treba mjeriti

- vrijeme izvođenja
- broj operacija
- memorijsku potrošnju (procjena ili alat)

#### Organizacija

Framework mora omogućiti:

- definiranje scenarija (npr. "insert N elemenata")
- pokretanje nad više struktura
- ponovljivost (isti input)

#### Analiza

Najvažniji dio je **interpretacija rezultata**. Studenti trebaju objasniti:

- zašto je nešto brže/sporije
- kako se ponaša za male vs velike ulaze

### Očekivani rezultat

- alat za evaluaciju struktura
- konkretni podaci (ne samo teorija)
- razumijevanje performansi u praksi
