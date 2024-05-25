/*
	Leo Petrovic 2174/RR

	Zadatak 4. - Modelirati vrtuljak (ringispil) s dva tipa dretvi/procesa: dretvama/procesima posjetitelj (koje predstavljaju posjetitelje koji zele na voznju) te dretvom/procesom vrtuljak. Dretvama/procesima posjetitelj se ne smije dozvoliti ukrcati na vrtuljak kada vise nema praznih mjesta (kojih je ukupno N) te prije nego li svi prethodni posjetitelji sidju. Vrtuljak se moze pokrenuti tek kada je pun. Za sinkronizaciju koristiti opce semafore i dodatne varijable.

	Upute:
	- Dretva posjetitelj() {
			...
			sjedi;
			...
			ustani; // ili sidji
			...
		}

	- Dretva vrtuljak() {
			dok je(1) {
			...
			pokreni vrtuljak;
			zaustavi vrtuljak;
			...
			}
		}
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SLOWMODE 1 // 1 za sporo izvrsavanje, 0 za brzo izvrsavanje
#define BROJ_SJEDALA 5

sem_t sem_sva_sjedala_zauzeta; // Semafor za signalizaciju da su sva sjedala zauzeta
sem_t sem_voznja_gotova;			 // Semafor za signalizaciju da je voznja gotova
sem_t sem_vrtuljak_prazan;		 // Semafor za signalizaciju da je vrtuljak prazan
sem_t sem_sjedalo_mutex;			 // Koristimo semafor kao mutex za zauzimanje sjedala

int zauzeta_sjedala = 0; // Broj zauzetih sjedala

void *posjetitelj(void *arg)
{
	long id = (long)arg;
	while (1)
	{
		// Cekaj dok vrtuljak ne bude prazan
		sem_wait(&sem_vrtuljak_prazan);

		// Pokusat zauzeti sjedalo
		sem_wait(&sem_sjedalo_mutex);
		if (zauzeta_sjedala < BROJ_SJEDALA) // Ako ima slobodnih mjesta...
		{
			// ...zauzmi sjedalo
			zauzeta_sjedala++;
			if (SLOWMODE)
				sleep(1); // Treba 1 sekunda da posjetitelj sjedne
			printf("Posjetitlj %ld je zauzeo mjesto. Broj zauzetih mjesta: %d\n", id, zauzeta_sjedala);
			if (zauzeta_sjedala == BROJ_SJEDALA) // Ako su sva sjedala zauzeta...
			{
				sleep(1);														// Dodajemo jos jednu sekundu delay da vrtuljak ne pocne iste sekunde kad i zadnji posjetitelj sjedne
				sem_post(&sem_sva_sjedala_zauzeta); // ...signaliziraj da su sva sjedala zauzeta
			}
			sem_post(&sem_sjedalo_mutex); // Oslobodi mutex da bi dopustio drugim posjetiteljima da zauzmu sjedala
		}
		else // Ako nema slobodnih mjesta...
		{
			// ...oslobodi mutex i cekaj da vrtuljak zavrsi voznju, zatim pokusaj ponovno
			sem_post(&sem_sjedalo_mutex);
			sem_post(&sem_vrtuljak_prazan); // Otpusti lock za ostale posjetitelje
			if (SLOWMODE)
				usleep(1000); // Mali delay da se sprijeci busy waiting. Nije potrebno u brzom modu
			continue;
		}

		// Cekaj dok vrtuljak ne zavrsi voznju
		sem_wait(&sem_voznja_gotova);

		// Posjetitelj silazi s vrtuljka
		sem_wait(&sem_sjedalo_mutex);
		zauzeta_sjedala--;
		if (zauzeta_sjedala + 1 == BROJ_SJEDALA)
		{
			sleep(1); // Dodajemo jos jednu sekundu delay da posjetitelj ne sidje iste sekunde kad i voznja zavrsi
		}
		printf("Posjetitelj %ld je sisao sa vrtuljka. Broj zauzetih mjesta: %d\n", id, zauzeta_sjedala);
		if (SLOWMODE)
			sleep(1); // Treba 1 sekunda da posjetitelj sidje
		sem_post(&sem_sjedalo_mutex);

		// Ako su sva sjedala prazna, signaliziraj da je vrtuljak prazan
		if (zauzeta_sjedala == 0)
		{
			for (int i = 0; i < BROJ_SJEDALA; i++)
			{
				sem_post(&sem_vrtuljak_prazan); // Dopusti novim posjetiteljima da zauzmu sjedala
			}
		}
	}
	return NULL;
}

void *vrtuljak(void *arg)
{
	while (1)
	{
		// Cekaj dok sva sjedala nisu zauzeta
		sem_wait(&sem_sva_sjedala_zauzeta);

		// Zapocni voznju
		printf("Vrtuljak pocinje!\n");
		// Trajanje voznje
		if (SLOWMODE)
			sleep(3);
		else
			sleep(1);
		printf("Vrtuljak zavrsio!\n");

		// Signaliziraj posjetiteljima da silaze jedan po jedan
		for (int i = 0; i < BROJ_SJEDALA; i++)
		{
			sem_post(&sem_voznja_gotova);
			if (SLOWMODE)
				sleep(1); // Treba 1 sekunda da posjetitelj sidje
		}

		// Svi posjetitelji moraju sici prije nego sto mozemo drugim posjetiteljima dopustiti da sjednu
		while (zauzeta_sjedala > 0)
		{
			if (SLOWMODE)
				usleep(1000); // Mali delay da se sprijeci busy waiting
		}

		printf("Vrtuljak je prazan!\n");
	}
	return NULL;
}

int main()
{
	pthread_t vrtuljak_dretva;
	pthread_t posjetitelj_dretve[10];

	sem_init(&sem_sva_sjedala_zauzeta, 0, 0);
	sem_init(&sem_voznja_gotova, 0, 0);
	sem_init(&sem_vrtuljak_prazan, 0, BROJ_SJEDALA);
	sem_init(&sem_sjedalo_mutex, 0, 1);

	printf("Vrtuljak je spreman!\n");

	pthread_create(&vrtuljak_dretva, NULL, vrtuljak, NULL);

	printf("Posjetitelji dolaze!\n");

	for (long i = 0; i < 10; i++)
	{
		pthread_create(&posjetitelj_dretve[i], NULL, posjetitelj, (void *)i);
	}

	for (int i = 0; i < 10; i++)
	{
		pthread_join(posjetitelj_dretve[i], NULL);
	}

	sem_destroy(&sem_sva_sjedala_zauzeta);
	sem_destroy(&sem_voznja_gotova);
	sem_destroy(&sem_vrtuljak_prazan);
	sem_destroy(&sem_sjedalo_mutex);

	return 0;
}
