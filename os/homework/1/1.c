// Ovo je zbog nekog razloga potrebno da bi koristili funkciju sigaction.
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <math.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 1.

	- Neka program simulira neki dugotrajni posao (slično servisima) koji koristi dvije datoteke: u jednu dodaje do sada izračunate vrijednosti (npr. kvadrati slijednih brojeva), a u drugu podatak do kuda je stigao. Npr. u obrada.txt zapisuje 1 4 9... (svaki broj u novi red) a u status.txt informaciju o tome gdje je stao ili kako nastaviti. Npr. ako je zadnji broj u obrada.txt 100 u status.txt treba zapisati 10 tako da u idućem pokretanju može nastaviti raditi i dodavati brojeve.
	- Prije pokretanja te je datoteke potrebno ručno napraviti i inicijalizirati. Početne vrijednosti mogu biti iste – broj 1 u obje datoteke.
	- Pri pokretanju programa on bi trebao otvoriti obje datoteke, iz status.txt, pročitati tamo zapisanu vrijednost. Ako je ona veća od nule program nastavlja s proračunom s prvom idućom vrijednošću i izračunate vrijednosti nadodaje u obrada.txt. Prije nastavka rada u status.txt upisuje 0 umjesto prijašnjeg broja, što treba označavati da je obrada u tijeku, da program radi.
	- Na signal (npr. SIGUSR1) program treba ispisati trenutni broj koji koristi u obradi. Na signal SIGTERM otvoriti status.txt i tamo zapisati zadnji broj (umjesto nule koja je tamo) te završiti s radom.
	- Na SIGINT samo prekinuti s radom, čime će u status.txt ostati nula (čak se taj signal niti ne mora maskirati – prekid je pretpostavljeno ponašanje!). To će uzrokovati da iduće pokretanje detektira prekid – nula u status.txt, te će za nastavak rada, tj. Određivanje idućeg broja morati „analizirati“ datoteku obrada.txt i od tamo zaključiti kako nastaviti (pročitati zadnji broj i izračunati korijen). Operacije s datotekama, radi jednostavnosti, uvijek mogu biti u nizu open+fscanf/fprintf+close, tj. ne držati datoteke otvorenima da se izbjegnu neki drugi problemi. Ali ne mora se tako. U obradu dodati odgodu (npr. sleep(5)) da se uspori izvođenje.
*/

// Globalne varijable
int broj;
const char obrada_dat_naziv[] = "obrada.txt";
const char status_dat_naziv[] = "status.txt";

// Ova funkcija se poziva kada se dogodi signal. Trenutno slusamo samo signale SIGUSR1 i SIGTERM.
void obradi_signal(int sig)
{
	FILE *status_dat;

	switch (sig)
	{
	// Ako je signal SIGUSR1, onda ispisemo trenutni broj.
	case SIGUSR1:
		printf("Trenutni broj: %d\n", broj);
		break;
	// Ako je signal SIGTERM, onda prvo zapisemo trenutni broj u status datoteku kako bi program mogao nastaviti gdje je zadnje stao kada se ponovno pokrene, zatim zavrsimo program.
	case SIGTERM:
		status_dat = fopen(status_dat_naziv, "w");

		if (status_dat == NULL)
		{
			printf("Greska pri otvaranju datoteke statusa.\n");
			exit(1);
		}

		// Zapisi trenutni broj u status datoteku.
		fprintf(status_dat, "%d", broj);
		fflush(status_dat);

		fclose(status_dat);

		exit(0);
		break;
	default:
		exit(0);
		break;
	}
}

// Ova funkcija obraduje posao. U ovom slucaju to je samo kvadriranje trenutnog broja i zapisivanje u datoteku obrade, no dodajemo lazni sleep kako bi simulirali dugotrajan posao.
void obradi_posao(FILE *obrada_dat)
{
	// Obrada posla (u ovom slucaju to je samo kvadriranje broja).
	fprintf(obrada_dat, "%d ", broj * broj);

	// Osiguraj da se promjene zapisu u datoteku.
	fflush(obrada_dat);

	// Spavaj 1 sekundu. Na ovaj nacin simuliramo neki zahtjevan/dugotrajan posao.
	// Potrebno je koristiti nanosleep (umjesto sleep) i ovu posebnu provjeru pomocu errno i EINTR jer osim signala SIGALARM, signal SIGUSR1 takodjer moze prekinuti sleep poziv prije nego sto jedna sekunda prodje, sto ne zelimo jer zelimo da se obrada izvrsi samo tocno jednom svake sekunde.
	struct timespec req = {1, 0}, rem;
	while (nanosleep(&req, &rem) == -1 && errno == EINTR)
	{
		req = rem;
	}
}

// Ova funkcija analizira datoteku obrade i vraca zadnji broj iz nje. Koristi se u slucaju da status datoteka nije uspjesno procitana.
// Ako ni ova funkcija ne uspije procitati zadnji broj, onda se status resetira na pocetnu vrijednost (1).
void analiziraj_obradu(FILE *obrada_dat)
{
	int temp;

	// "r" mod za citanje znaci da ce obrada_dat biti NULL ako datoteka ne postoji.
	obrada_dat = fopen(obrada_dat_naziv, "r");

	// Ako datoteka obrade ne postoji...
	if (obrada_dat == NULL)
	{
		// ...onda ju stvori.
		// "w" mod za pisanje znaci da ce datoteka biti izbrisana (ako vec postoji) te stvorena iznova.
		obrada_dat = fopen(obrada_dat_naziv, "w");

		printf("Datoteka obrade ne postoji. Pretpostavljam da je ovo prvo pokretanje programa. Stvaram datoteku obrade i resetiram status na pocetnu vrijednost.\n");

		// Postavi status na pocetnu vrijednost.
		broj = 1;

		return;
	}

	// Ako datoteka obrade postoji, analiziraj ju.
	// Beskonacna petlja koja ce se prekinuti kada se procita zadnji broj iz datoteke obrade.
	while (1)
	{
		// Procitaj broj iz datoteke obrade.
		// Ako nismo uspjeli procitati tocno jedan podatak iz datoteke, onda ce se if blok izvrsiti.
		if (fscanf(obrada_dat, "%d", &broj) != 1)
		{
			// Ako smo dosli do kraja datoteke, onda je rezultat fscanf iznad jednak EOF. U tom slucaju prekini petlju.
			if (feof(obrada_dat))
			{
				break;
			}

			// U bilo kojem drugem slucaju, citanje je neuspjesno, zbog toga prekini petlju, prebrisi datoteku obrade, te obavijesti korisnika.
			printf("Greska: neuspjesno citanje datoteke obrade. Resetiram status na pocetnu vrijednost i resetiram datoteku obrade.\n");

			// Prebrisi datoteku obrade.
			obrada_dat = fopen(obrada_dat_naziv, "w");

			broj = 1;

			break;
		}
	}

	// Trenutni broj bi trebao biti korijen zadnjeg broja u datoteci obrade.
	temp = sqrt(broj);

	// Ako procitani broj nije kvadrat cijelog broja, onda je datoteka obrade neispravna pa ju treba resetirati.
	if (temp * temp != broj)
	{
		printf("Greska: zadnji broj u datoteci obrade nije kvadrat cijelog broja. Resetiram status na pocetnu vrijednost i resetiram datoteku obrade.\n");

		// Prebrisi datoteku obrade.
		obrada_dat = fopen(obrada_dat_naziv, "w");

		broj = 1;

		return;
	}

	broj = temp;
}

// Ova funkcija procitava statusni broj iz status datoteke.
// Ako status datoteka ne postoji ili sadrzi neispravne podatke, pokusava analizirati datoteku obrade da bi saznala status.
// Ako ne mozemo ni iz datoteke obrade procitati status, onda se pretpostavlja da je ovo prvo pokretanje programa i resetira se status na pocetnu vrijednost.
void procitaj_broj(FILE *status_dat, FILE *obrada_dat)
{
	status_dat = fopen(status_dat_naziv, "r");

	// Ako status datoteka ne postoji...
	if (status_dat == NULL)
	{
		// ...onda ju stvori, zatim pokusaj analizirati datoteku obrade.
		status_dat = fopen(status_dat_naziv, "w");

		printf("Datoteka statusa ne postoji. Pretpostavljam da je ovo prvo pokretanje programa. Stvaram datoteku statusa i pokusavam analizirati datoteku obrade.\n");

		analiziraj_obradu(obrada_dat);
	}
	else
	{
		// Ako status datoteka postoji, procitaj broj iz nje.
		if (fscanf(status_dat, "%d", &broj) != 1)
		{
			// Ako je citanje neupejesno, onda pokusaj procitati iz datoteke obrade.
			printf("Greska: neuspjesno citanje status datoteke. Pokusavam analizirati datoteku obrade.\n");

			analiziraj_obradu(obrada_dat);
		}
		else
		{
			// Ako je citanje uspjesno, no procitani broj je 0, to znaci da je obrada u tijeku od strane nekog drugog procesa ili da je prosla obrada prekinuta prisilno.
			if (broj == 0)
			{
				printf("Greska: obrada je vec u tijeku. Pokusajte ponovno kasnije.\n");
				exit(1);
			}

			printf("Usjesno procitan status iz datoteke statusa: %d.\n", broj);
		}
	}
}

int main()
{
	FILE *obrada_dat;
	FILE *status_dat;

	// Pokusamo procitati broj iz datoteke status.txt, odnosno obrada.txt ako to ne uspije. Ako ni to ne uspije, onda se broj postavlja na pocetnu vrijednost (1). Broj je globalna varijabla.
	procitaj_broj(status_dat, obrada_dat);

	// Ako statusni broj nije pocetna vrijednost (1), onda obrađujemo sljedeci broj. Razlog zasto ovo radimo je da se broj unutar datoteke obrade ne bi duplicirao prilikom nastavljanja obrade. (npr. ako smo prekinuli program dok je status bio broj 5, onda broj 25 vec postoji u datoteci obrade, pa bi se broj 25 duplicirao ako bi nastavili obradu od statusnog broja 5).
	if (broj != 1)
	{
		broj++;
	}

	printf("Obrada se nastavlja sa brojem %d.\n", broj);

	// Vazno: datoteka obrade se otvara u "a" modu kako bi se nastavilo pisati na kraj datoteke tj. da se ne bi izbrisali podaci koji su vec unutra.
	// Datoteka statusa se otvara u "w" modu kako bi se prebrisala stara vrijednost statusa.
	obrada_dat = fopen(obrada_dat_naziv, "a");
	status_dat = fopen(status_dat_naziv, "w");

	if (obrada_dat == NULL || status_dat == NULL)
	{
		printf("Greska pri otvaranju datoteka.\n");

		fclose(obrada_dat);
		fclose(status_dat);

		return 1;
	}

	// Postaviti status u nulu kako bi oznacili da je obrada u tijeku.
	fprintf(status_dat, "%d", 0);
	fflush(status_dat);

	// Maskiranje signala. Koristimo sigaction umjesto signal jer je signal zastario. Za sigaction moramo definirati strukturu sigaction kako bi ga koristili.
	struct sigaction obradi_signal_action = {0};
	obradi_signal_action.sa_handler = obradi_signal;
	sigemptyset(&obradi_signal_action.sa_mask);

	// Maskiramo signale SIGUSR1 i SIGTERM. Kada program primi ove signale, pozvat ce se funkcija obradi_signal. Ta funkcija ce takodjer kao argument primiti signal koji je program primio.
	sigaction(SIGUSR1, &obradi_signal_action, NULL);
	sigaction(SIGTERM, &obradi_signal_action, NULL);

	// Dugotrajni proces.
	while (1)
	{
		obradi_posao(obrada_dat);

		broj++;
	}

	fclose(obrada_dat);
	fclose(status_dat);

	return 0;
}