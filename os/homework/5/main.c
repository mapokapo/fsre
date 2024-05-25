/*
	Leo Petrovic 2174/RR

	Zadatak 5. - S pomoću više dretvi riješiti problem pet filozofakoristeći koncept monitora. Pri svakoj promjeni program mora vizualno prikazati za sve filozofe što oni rade. Npr. kada filozof 4 ide jesti, tada treba ispis izgledati otprilike ovako: "Stanje filozofa: X o O X o" (X-jede, O-razmišlja, o-čeka na vilice).

	- Problem pet filozofa. Filozofi obavljaju samo dvije različite aktivnosti: misle ili jedu. To rade na poseban način. Na jednom okruglom stolu nalazi se pet tanjura te pet štapića (između svaka dva tanjura po jedan). Filozof prilazi stolu, uzima lijevi štapić, pa desni te jede. Zatim vraća štapiće na stol i odlazi misliti.

	- Ako rad filozofa predstavimo jednim zadatkom onda se on može opisati na sljedeći način:
			filozof i
				ponavljati
					misliti;
					jesti;
				do zauvijek;
	- Potrebno je pravilno sinkronizirati rad filozofa. Uporabom binarnog semafora za pojedine štapiće može doći do potpunog zastoja (kada svi istovremeno uzmu lijevi štapić). Problem se može riješiti uvođenjem dodatnog općeg semafora koji će ograničavati broj filozofa za stolom.
	- Međutim, u općem slučaju kada zadaci dijele više sredstava i koriste ih više istovremeno semafori mogu uzrokovati potpuni zastoj. Upravo zbog takvih problema dijeljenja više sredstava među više zadataka uvodi se novi mehanizam za sinkronizaciju: monitori.
	- Za ostvarenje monitora u višedretvenom programu stoje na raspolaganju funkcije međusobnog isključavanja te funkcije za rukovanje uvjetnim varijablama koje služe za ostvarenje reda uvjeta.
	- Pseudokod pretvoriti u dio programa koji radi svaka dretva tako da misliti i jesti postaju funkcije. Funkcija misliti() treba simulirati trošenje vremena (npr. sleep(3)). Funkcija jesti(n) simulira postupak hranjenja filozofa s uključivo potrebnim kodom sinkronizacije koji je skiciran u nastavku.
	- Pseudokod:
		jesti(n) { // n - redni broj filozofa
			uđi_u_kritični_odsječak;
			filozof[n] = 'o';

			dok (vilica[n] == 0 || vilica[(n + 1) % 5] == 0)
				čekaj_u_redu_uvjeta(red[n]);
			vilica[n] = vilica[(n + 1) % 5] = 0;

			filozof[n] = 'X';

			ispiši_stanje(n);
			izađi_iz_kritičnog_odsječka;

			njam_njam; // sleep (2);

			uđi_u_kritični_odsječak;
			filozof[n] = 'O';

			vilica[n] = vilica[(n + 1) % 5] = 1;

			oslobodi_dretvu_iz_reda(red[(n - 1) % 5]);
			oslobodi_dretvu_iz_reda(red[(n + 1) % 5]);

			ispiši_stanje(n);
			izađi_iz_kritičnog_odsječka;
		}
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BROJ_FILOZOFA 5

struct monitor
{
	char stanje[BROJ_FILOZOFA]; // 'X' - jede, 'O' - razmišlja, 'o' - čeka na vilice
	int vilice[BROJ_FILOZOFA];	// 1 - dostupno, 0 - zauzeto
	pthread_mutex_t mutex;
	pthread_cond_t red[BROJ_FILOZOFA];
};

struct filozof_podaci
{
	int id; // id dretve
	struct monitor *m;
};

// Inicijalizacija monitora tj. mutex-a za sve dretve, te uvjetnih varijabli i stanja monitora za pojedine dretve
void init_monitor(struct monitor *m)
{
	pthread_mutex_init(&m->mutex, NULL);
	for (int i = 0; i < BROJ_FILOZOFA; i++)
	{
		m->stanje[i] = 'O'; // Svi filozofi na pocetku razmisljaju
		m->vilice[i] = 1;		// Sve vilice na pocetku su dostupne (na stolu)
		pthread_cond_init(&m->red[i], NULL);
	}
}

void misli()
{
	sleep(3);
}

void jedi()
{
	sleep(2);
}

void udji_u_kriticni_odsječak(struct monitor *m)
{
	pthread_mutex_lock(&m->mutex);
}

void izadji_iz_kriticnog_odsjecka(struct monitor *m)
{
	pthread_mutex_unlock(&m->mutex);
}

void ispisi_stanje(struct monitor *m, int id)
{
	printf("[%d] Stanje filozofa: ", id + 1);
	for (int i = 0; i < BROJ_FILOZOFA; i++)
	{
		printf("%c ", m->stanje[i]);
	}
	printf("\n");
}

void spusti_vilice(struct monitor *m, int id)
{
	m->vilice[id] = 1;											 // Spusti lijevu vilicu
	m->vilice[(id + 1) % BROJ_FILOZOFA] = 1; // Spusti desnu vilicu

	pthread_cond_signal(&m->red[(id - 1 + BROJ_FILOZOFA) % BROJ_FILOZOFA]); // Oslobodi lijevu vilicu susjedu s lijeve strane
	pthread_cond_signal(&m->red[(id + 1) % BROJ_FILOZOFA]);									// Oslobodi desnu vilicu susjedu s desne strane
}

void jedi_i_misli(struct monitor *m, int id)
{
	while (1)
	{
		misli(); // Cekamo 3 sekunde dok filozof razmislja

		/* START KRITICNI ODSJECAK - JEDENJE */
		udji_u_kriticni_odsječak(m);

		m->stanje[id] = 'o'; // Filozof čeka na vilice

		while (!m->vilice[id] || !m->vilice[(id + 1) % BROJ_FILOZOFA])
		{
			pthread_cond_wait(&m->red[id], &m->mutex); // Cekaj sve dok ne dobijemo signal za dretvu sa ID brojem "id".
																								 // U slucaju da smo dobili signal, no dretva koja je poslala signal nije postavila stanje na vrijednost koja zadovolja uvjet, onda ce while petlja osigurati da se dretva ne nastavi izvrsavati, te ce ponovno cekati na signal. Na taj nacin smo izbjegli "spurious wakeup".
		}

		m->vilice[id] = 0;											 // Uzmi lijevu vilicu
		m->vilice[(id + 1) % BROJ_FILOZOFA] = 0; // Uzmi desnu vilicu
		m->stanje[id] = 'X';										 // Filozof jede

		ispisi_stanje(m, id);

		izadji_iz_kriticnog_odsjecka(m);
		/* END KRITICNI ODSJECAK - JEDENJE */

		jedi(); // Cekamo 2 sekunde dok filozof jede

		/* START KRITICNI ODSJECAK - MISLJENJE */
		udji_u_kriticni_odsječak(m);

		m->stanje[id] = 'O'; // Filozof razmišlja

		spusti_vilice(m, id); // Spustanje vilica ce osloboditi dretve (susjedne filozofe) koji su cekali na te vilice

		ispisi_stanje(m, id);

		izadji_iz_kriticnog_odsjecka(m);
		/* END KRITICNI ODSJECAK - MISLJENJE */
	}
}

void *filozof_dretva(void *arg)
{
	struct filozof_podaci *fp = (struct filozof_podaci *)arg;

	jedi_i_misli(fp->m, fp->id);

	return NULL;
}

int main()
{
	struct monitor m;
	pthread_t filozofi[BROJ_FILOZOFA];
	struct filozof_podaci fp[BROJ_FILOZOFA]; // Podaci koji se salju dretvama

	init_monitor(&m);

	for (int i = 0; i < BROJ_FILOZOFA; i++)
	{
		fp[i].id = i;
		fp[i].m = &m;
		pthread_create(&filozofi[i], NULL, filozof_dretva, &fp[i]);
	}

	for (int i = 0; i < BROJ_FILOZOFA; i++)
	{
		pthread_join(filozofi[i], NULL);
	}

	return 0;
}