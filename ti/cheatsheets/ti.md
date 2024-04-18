# Teorija Informacije

## Prezentacija 1

### Definicija

- Teorija informacije je matematička teorija, temeljena na statistici i teoriji vjerojatnosti
  koja se bavi komunikacijom na sto brzi i tocniji nacin uz minimalnu potrosnju energije i gubitak podataka. Zadatci su joj:

  - Stvaranje modela komunikacijskog sustava
  - Racuna mjeru informacije (koliko informacije u prosjeku sadrzi svaki simbol poruke)
  - Racuna broj simbola potreban za prijenos poruke bez gubitka informacije (granica kompresije bez gubitka)
  - Racuna granice kolicine informacije koja se moze prenijeti komunikacijskim kanalom u jedinici vremena (kapacitet kanala)

### Podatci i informacija

- Podatak je neobradjeni/neorganizirani materijal bez znacenja (slovo, broj, itd.), dok je informacija skup obradjenih podataka koji ima znacenje (ime, cijena, itd.).
- Postoje 3 obiljezja informacije:

  1. Sintakticko - pokazuje oblik poruke (odnosi izmedju simbola koji cine poruku)
  2. Semanticko - pokazuje znacenje poruke
  3. Pragmaticko - pokazuje svrhu (vaznost, relevantnost...) poruke

  Sintakticko obiljezje uglavnom razmatra oblik/format informacije, dok semanticko i pragmaticko obiljezje su vezane uz sami sadrzaj.

### Razlicita poimanja teorije informacije

- Postoje 2 razlicita poimanja teorije informacije:
  1.  Britanski pristup - istrazuje pragmaticko i semanticko obiljezje informacije (znacnje i vaznost)
  2.  Americki pristup - istrazuje sintakticko obiljezje informacije (oblik i format).

### Komunikacijski sustav

- Komunikacija je razmjena informacija, a teorija informacije postavlja model komunikacijskog sustava (nacin na koji se komunicira). Postoje 3 faze komunikacije:

  1.  Kodiranje
  2.  Prijenos
  3.  Dekodiranje

  Vazno je da je informacija upucena tocnom primatelju i u formatu koji on moze razumjeti.

  Komunikacija se apstraktnije moze definirati kao: reproduciranje poruke na jednoj tocki (odrediste) koja je odabrana na nekoj drugoj tocki (izvor).

  Vazni pojmovi vezani za komunikaciju su:

  - Posiljatelj (izvor)
  - Primatelj (odrediste)
  - Kod
  - Kanal
  - Poruka
  - Kontekst

  Komunikacijski sustav je cjelokupni sustav prijenosa poruke. To ukljucuje pretvaranje poruke u signal (sa strane posiljatelja) i pretvaranje signala u poruku (sa strane primatelja). Glavna zadaca komunikacijskog sustava je prenos informacija od izvora do odredista. Komunikacijski sustavi se mogu podijeliti po broju sudionika (jedan na jedan, jedan na vise, vise na jedan, vise na vise) i po nacinu prijenosa (jednosmjerni, dvosmjerni).

### Zastitno kodiranje

- Hammingovo rastojanje je mjera pogresnosti poruke, tocnije to je broj bitova u kojima se razlikuju dvije poruke. Npr. za poruke 1010 i 1001, minimalna Hammingova udaljenost je 2 (potrebne su minimalno 2 promjene da bi se jedna poruka pretvorila u drugu).

- **Tezina kodne rijeci** - broj jedinica u kodnoj rijeci. Npr. za 1010, tezina je 2.

### Paritetno kodiranje

- Koristi se iskljucivo za otkrivanje gresaka u kodnoj rijeci, a ne i za popravljanje tih gresaka.
- Postupak: na poruku se dodaje jedan dodatni bit koji se naziva paritetni bit. Taj bit moze predstavljati parni ili neparni paritet - ako se ispravnom porukom smatra ona koja ima paran broj jedinica, to je parni paritet, i obratno. Paritetni bit ce se postaviti tako da ta poruka ima broj jedinica koji odgovara zadanom paritetu.

### Krizni paritet

- Koristi se za otkrivanje i popravljanje gresaka u kodnoj rijeci.
- Postupak: za svaki redak matrice kodne rijeci se izracuna paritet, te se doda na kraj tog retka. Isti postupak se ponovi i za stupce. Na kraju ostane prazno polje u donjem desnom kutu, koje se popuni tako da se izracuna paritet svih bitova u matrici. Na ovaj nacin se moze tocno odrediti koji bit je pogresan te se moze popraviti.

## Prezentacija 2

### Kolicina informacije i entropija

- Neke poruke sadrze vecu kolicinu informacije nego druge, a mjera **kolicine informacije** mjeri koliko informacije se sadrzi u poruci.

  Pravilo je da je kolicina informacije neke poruke obrnuto proporcionalna vjerojatnosti te poruke.

  Npr. ako nam netko kaze da je nebo plavo, ta poruka nema veliku kolicinu informacije jer je vjerojatnost da je nebo plavo vrlo velika, ali ako kazu da je nebo zuto, to nosi veliku kolicinu informacije jer je vjerojatnost da je nebo zuto vrlo mala.

  Mjera kolicine informacije se takodjer naziva i **neodredjenost**, a moze se izracunati formulom: $I(x)=-log_2p(x)$, gdje je $p(x)$ vjerojatnost poruke x. Koristi se logaritam baze 2 jer je korisno informaciju mjeriti u bitovima. Zbog toga kolicina informacije takodjer ne moze biti negativna.

  Mjera kolicine informacije je vazna za kodiranje informacija kroz komunikacijski kanal.

  **Vazno:** zdruzena vjerojatnost pojavljivanja nekih dviju poruka je jednaka umnozku njihovih pojedinacnih vjerojatnosti: $p(x,y) = p(x) \cdot p(y)$ samo ako su te dvije poruke nezavisne.

### Entropija

- Entropija je srednja vrijednost kolicine informacije koja prolazi tockom izvora u komunikacijskom sustavu.

  Ona je korisna jer se u komunikacijskim sustavima inace prenosi duzi niz simbola, pa je lakse izracunati srednju vrijednost za sviju njih umjesto koristenja pojedinacnih vrijednosti. Ona je brojcano jednaka: $H(x) = -\sum_{i=1}^{n}p(x_i) \cdot log_2p(x_i)$, gdje je $p(x_i)$ vjerojatnost pojedinog simbola.

  Ako su sve poruke na izvoru jednako vjerojatne, entropija je maksimalna. Brojcano to je jednako: $H_{max}(x) = log_2n$, gdje je n broj simbola.

  Dodatne formule:

  - redundancija: $red = 1 - \frac{H(x)}{H_{max}(x)}$
  - brzina prijenosa informacija: $R = r \cdot H$, r je brzina poruka

## Prezentacija 3

### Prenesena kolicina informacije

- To je mjera povezanosti/ovisnosti dogadjaja X i Y
- Odredjuje koliko informacije mozemo dobiti o jednom dogadjaju ako znamo da se drugi dogadjaj dogodio. Formula je: $I(x;y)=\sum_{i=1}^N\sum_{j=1}^Mp(x_i,y_j) \cdot log_2\frac{p(x_i,y_j)}{p(x_i)p(y_j)}$, gdje je p(x,y) zajednicka vjerojatnost pojavljivanja dogadjaja x i y.

  Ova formula mjeri koliko je informacija zajednickih za oba dogadjaja u usporedbi sa informacijom koju bi dobili da ih promatramo zasebno. Ako su X i Y nezavisni, onda je $I(x;y)=0$.

  - H(X) - entropija izvora, odnosno mjera neizvjesnosti koji simbol ce biti poslan
  - H(Y) - entropija odredista, odnosno mjera neizvjesnosti koji simbol ce biti primljen
  - H(Y/X) - mjera neizvjesnosti koji ce simbol biti primljen na odredistu ako je poznato koji je simbol poslan
  - H(X/Y) - mjera neizvjesnosti koji je simbol poslan ako je poznato koji je simbol primljen na odredistu

  $I(x;y) = H(X) - H(X/Y) = H(Y) - H(Y/X) = H(X) + H(Y) - H(X,Y)$

  Lakse zapamtiti: H(X) su informacije koje su poslane, H(Y) su informacije koje su primljene. I(x;y) su informacije koje su uspjesno poslane i primljene. H(X/Y) su informacije koje su poslane, ali nisu stigle (kanal sa brisanjem), a H(Y/X) su informacije koje su stigle, ali nisu zapravo bile poslane (kanal sa greskom).

## Prezentacija 4

## Entropijsko kodiranje

- To je postupak zapisivanja poruka iz izvora u najoptimalnijem obliku. Tom metodom se dobiju kodovi minimalne duljine koji jednoznacno opisuju poslane poruke. Ideja je da se porukama sa vecom vjerojatnoscu dodijele krace kodne rijeci.
- Efikasnost koda: $\eta = \frac{H(x)}{L\cdot log_2r}$, gdje je L prosjecna ponderirana duljina kodne rijeci, a r duljina kodne abecede.
