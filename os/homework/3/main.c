/*
	Leo Petrovic 2174/RR

	Zadatak 3. - Ostvariti program koji simulira tijek rezervacije stolova u nekom restoranu. Program na početku treba stvoriti određeni broj dretvi koji se zadaje u naredbenom retku. Svaka dretva/proces nakon isteka jedne sekunde provjerava ima li slobodnih stolova te slučajno odabire jedan od njih. Nakon odabira, dretva ulazi u kritični odsječak te ponovo provjerava je li odabrani stol slobodan. Ako jest, označava stol zauzetim i izlazi iz kritičnog odsječka. U oba slučaja, nakon obavljene operacije, ispisuje se trenutno stanje svih stolova te podatci o obavljenoj rezervaciji. Prilikom ispisa za svaki stol mora biti vidljivo je li slobodan, ili ako nije, broj dretve/procesa koja je taj stol rezervirala. Broj stolova se također zadaje u naredbenom retku. Svaka dretva ponavlja isti postupak sve dok više nema slobodnih stolova. Program završava kada sve dretve završe.

	Primjer ispisa za 3 dretve i 5 stolova:
		Dretva 1: odabirem stol 2
		Dretva 2: odabirem stol 2
		Dretva 3: odabirem stol 5
		Dretva 2: rezerviram stol 2, stanje:
		-2---
		Dretva 1: neuspjela rezervacija stola 2, stanje:
		-2---
		Dretva 3: rezerviram stol 5, stanje:
		-2--3
		itd.
	Upute:
		- Zaštitu kritičnog odsječka postupka rezervacije stola ostvariti koristeći Lamportov algoritam međusobnog isključivanja.

	Lamportov algoritam:
 - Zajedničke varijable: ULAZ[0..n-1], BROJ[0..n-1], sve početno postavljene u nulu.
	- uđi_u_kritični_odsječak(i)
			ULAZ[i] = 1
			BROJ[i] = max ( BROJ[0], ..., BROJ[n-1] ) + 1
			ULAZ[i] = 0

			za j = 0 do n-1 čini
				dok je ULAZ[j] <> 0 čini
					ništa
				dok je BROJ[j] <> 0 && (BROJ[j] < BROJ[i] || (BROJ[j] == BROJ[i] && j < i)) čini
					ništa

	- izađi_iz_kritičnog_odsječka(i)
			BROJ[i] = 0

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

int *ULAZ; // oznacava koja dretva zeli uci u kriticni odsjecak
int *BROJ; // odrzava redoslijed dretvi koje zele uci u kriticni odsjecak, tako da se postuje FIFO redoslijed

int broj_dretvi;
int broj_stolova;

int *stolovi; // trenutno stanje rezerviranih stolova. -1 predstavlja slobodan stol, a ako nije -1 onda je to broj dretve koja je rezervirala stol

// Pronalazi najveci element u nizu niz koji ima n elemenata
int max(int *niz, int n)
{
	int najv = niz[0];

	for (int i = 0; i < n; i++)
	{
		if (niz[i] > najv)
		{
			najv = niz[i];
		}
	}

	return najv;
}

// Provjerava jesu li svi stolovi zauzeti. Ovo se koristi za prekid rada dretvi kada su svi stolovi zauzeti jer tada nemaju vise sta za raditi.
int je_li_sve_zauzeto()
{
	for (int i = 0; i < broj_stolova; i++)
	{
		if (stolovi[i] == -1)
		{
			return 0;
		}
	}

	return 1;
}

// Pomocna funkcija za provjeru alokacije memorije
void mecheck(void *ptr)
{
	if (ptr == NULL)
	{
		perror("(!) Neuspjela alokacija memorije!\n");
		exit(1);
	}
}

// Sastavlja string koji predstavlja trenutno stanje stolova, tj. koje dretve su rezervirale koji stol.
// Primjer za 3 dretva i 5 stolova: ako je dretva 1 rezervirala stol 2, i dretva 3 rezervirala stol 5, onda ce string biti "-2--3"
// Mora paziti na to da nemamo vise od 9 dretvi, jer bi onda ID broj dretve bio 2-znamenkast sto ne moze stati u jedan char za ispis.
void sastavi_stanje_string(char *stanje)
{
	for (int i = 0; i < broj_stolova; i++)
	{
		if (stolovi[i] == -1)
		{
			stanje[i] = '-';
		}
		else
		{
			stanje[i] = stolovi[i] + 1 + '0';
		}
	}

	stanje[broj_stolova] = '\0';
}

// Lamportov algoritam za međusobno isključivanje - ulazak u kriticni odsjecak. Oznacavamo da dretva "i" zeli obavljati posao, i tijekom tog rada, nijedna druga dretva ne smije uci u kriticni odsjecak.
void udi_u_kriticni_odsjeckak(int i)
{
	ULAZ[i] = 1;													 // označava da dretva "i" želi ući u kritični odsječak.
	BROJ[i] = max(BROJ, broj_stolova) + 1; // određuje redoslijed dretvi koje žele ući u kritični odsječak. Indeks niza je ID broj dretve, a vrijednost na tom indeksu je redoslijed ulaska u kriticni odsječak. Npr. ako je vrijednost 2, to znaci da trenutna dretva treba cekati jos jednu dretvu da se izvrsi prije nego sto moze poceti svoj rad. Svaka nova dretva koja dodje u red dobiva novi broj za 1 veci od prethodne dretve.
	ULAZ[i] = 0;													 // dretva "i" je vec "usla" u kriticni odsječak (u stvarnosti je samo usla u redoslijed ali to nam je jedino i vazno), pa sada moze pustiti druge dretve da ulaze.

	// provjeravamo moze li dretva "i" obavljati posao. Ako ne moze, onda ceka svoj red (putem beskonacne petlje)
	for (int j = 0; j < broj_stolova - 1; j++)
	{
		while (ULAZ[j] != 0) // dok je god neka druga dretva u procesu ulazenja u red cekanja za kriticni odsječak, cekamo.
		{
			; // ne radimo nista
		}
		while (BROJ[j] != 0 && (BROJ[j] < BROJ[i] || (BROJ[j] == BROJ[i] && j < i))) // dok god neka druga dretva ima prednost, cekamo.
		// Ako je BROJ[j] == BROJ[i] && j < i, onda dretva "j" ima prednost.
		// Ako je BROJ[j] == 0, onda je dretva "j" vec zavrsila s radom i nema prednost, pa ne moramo cekati i mozemo preskociti petlju.
		// Ako je BROJ[j] > BROJ[i], onda dretva "j" ima prednost, pa moramo cekati.
		{
			;
		}
	}
}

// Lamportov algoritam za međusobno isključivanje - izlazak iz kriticnog odsjecka. Oznacavamo da dretva "i" je zavrsila s radom, te sama sebe izbacuje iz redoslijeda dretvi koje zele uci u kriticni odsječak.
void izadi_iz_kriticnog_odsjecka(int i)
{
	BROJ[i] = 0; // dretva "i" je zavrsila s radom, pa sebe izbacuje iz redoslijeda dretvi koje zele uci u kriticni odsječak.
}

void *rezerviraj(void *arg)
{
	int id_dretve = *((int *)arg); // kopiramo broj koji je proslijedjen u dretvu u lokalnu varijablu
	free(arg);										 // oslobadamo memoriju jer nam vise ne treba

	while (1)
	{
		// svaku 1 sekundu dretva provjerava ima li slobodnih stolova
		sleep(1);

		if (je_li_sve_zauzeto())
		{
			break;
		}

		// ako ima slobodnih stolova, onda mozemo nastaviti s radom

		int stol = rand() % broj_stolova; // odabiremo nasumicni stol

		printf("[%d] 1 - Odabirem stol %d\n", id_dretve + 1, stol + 1);

		char *stanje = malloc((broj_stolova + 1) * sizeof(char));

		printf("[%d] 2 - Pokusavam uci u kriticni odsječak...\n", id_dretve + 1);
		udi_u_kriticni_odsjeckak(stol);
		printf("[%d] 3 - Usla u kriticni odsjecak, pokusavam rezervirati stol ako je slobodan...\n", id_dretve + 1);

		if (stolovi[stol] == -1) // ako je odabrani stol slobodan, onda ga rezerviramo
		{
			stolovi[stol] = id_dretve;

			printf("[%d] 4 - Uspjesno rezerviran stol %d\n", id_dretve + 1, stol + 1);
		}
		else
		{
			printf("[%d] 4 - Neuspjela rezervacija stola %d jer je zauzet\n", id_dretve + 1, stol + 1);
		}

		sastavi_stanje_string(stanje); // pomocna funkcija koja sastavlja string koji predstavlja trenutno stanje stolova

		printf("[%d] 5 - Stanje: %s\n", id_dretve + 1, stanje);

		izadi_iz_kriticnog_odsjecka(stol);

		free(stanje);
	}

	printf("[%d] (!) Svi stolovi su zauzeti! Gasim dretvu...\n", id_dretve + 1);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	if (argc != 3) // prvi argument je ime programa, drugi argument je broj dretvi, a treci argument je broj stolova
	{
		printf("(!) Krivi broj argumenata!\n");
		exit(1);
	}

	broj_dretvi = atoi(argv[1]);
	broj_stolova = atoi(argv[2]);

	if (broj_dretvi > 9) // maksimalno 9 dretvi. Vise informacija u komentaru iznad funkcije sastavi_stanje_string().
	{
		printf("(!) Maksimalan broj dretvi je 9!\n");
		exit(1);
	}

	ULAZ = malloc(broj_stolova * sizeof(int));
	BROJ = malloc(broj_stolova * sizeof(int));
	stolovi = malloc(broj_stolova * sizeof(int));

	mecheck(ULAZ); // pomocna funkcija za provjeru alokacije memorije. Vise informacija u komentaru iznad funkcije.
	mecheck(BROJ);
	mecheck(stolovi);

	// inicijalizacija varijabli
	for (int i = 0; i < broj_stolova; i++)
	{
		ULAZ[i] = 0;
		BROJ[i] = 0;
		stolovi[i] = -1;
	}

	srand(time(NULL)); // seed-anje generatora slucajnih brojeva

	pthread_t thread_ids[broj_dretvi]; // niz ID-eva dretvi

	// generiraom broj_dretvi dretvi
	for (int i = 0; i < broj_dretvi; i++)
	{
		int *id_dretve = malloc(sizeof(int));
		mecheck(id_dretve);

		*id_dretve = i; // ID dretve je redni broj dretve po redu stvaranja

		if (pthread_create(thread_ids + i, NULL, rezerviraj, id_dretve) != 0)
		{
			perror("(!) Neuspjelo stvaranje dretve!\n");
			exit(1);
		}
	}

	// svaku dretvu cekamo da zavrsi s radom
	for (int i = 0; i < broj_dretvi; i++)
	{
		pthread_join(thread_ids[i], NULL);
	}

	printf("Rezerviranje gotovo!\n");
	char *stanje = malloc((broj_stolova + 1) * sizeof(char));
	sastavi_stanje_string(stanje);
	printf("Stanje: %s\n", stanje);

	free(ULAZ);
	free(BROJ);
	free(stolovi);
	free(stanje);

	return 0;
}