/*
	Leo Petrovic 2174/RR

	Zadatak 2. - Međusobno isključivanje ostvariti za dva procesa/dretve međusobnim isključivanjem po Dekkerovom algoritmu.

	Upute:
	- Ako se program rješava s procesima tada treba zajedničke varijable tako organizirati da se prostor za njih zauzme odjednom i podijeli među njima. Ovo je nužno zbog ograničenog broja segmenata i velikog broja korisnika.
	- Ovisno o opterećenju računala i broju procesa koji se pokreću, a da bi se vidjele razlike prilikom izvođenja programa može biti potrebno usporiti izvršavanje sa sleep(1).
	- Nakon ispisi (i, k, m).

	Dekkerov postupak međusobnog isključivanja. Pseudokod:
		zajedničke varijable: PRAVO, ZASTAVICA[0..1]

		funkcija uđi_u_kritični_odsječak(i, j) {
			ZASTAVICA[i] = 1; // p1 želi ući
			while (ZASTAVICA[j] != 0) {
				// sve dok p2 želi ući
				if (PRAVO == j) {
					// ako p2 ima prednost
					ZASTAVICA[i] = 0;
					// p1 odustaje
					while (PRAVO=j) { } // čekaj
					ZASTAVICA[i] = 1;
					// pa javi da želi ući
				}
			}
		}

		funkcija izađi_iz_kritičnog_odsječka(i, j) {
			PRAVO = j; // prednost dajemo p2
			ZASTAVICA[i] = 0;
		}

	- Ostvariti sustav paralelnih procesa/dretvi.
	- Struktura procesa/dretvi dana je sljedećim pseudokodom:

		proces proc(i) // i [0..n-1]
			za k = 1 do N
				udji u kriticni odsjecak

				za m = 1 do N
					ispisi(i, k, m)

				izadji iz kriticnog odsjecka
		kraj.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define N 2

int SHMID; // shared memory id
int *PRAVO;
int *ZASTAVICA;

int *suma;

void udji_u_kriticni_odsječak(int i, int j)
{
	printf("(!) Proces %d trazi pristup od Dekkerovog algoritma\n", i);
	ZASTAVICA[i] = 1;					// i oznacava koji proces zeli uci, a vrijednost 1 predstavlja da zeli uci
	while (ZASTAVICA[j] == 1) // sve dok drugi proces zeli uci
	{
		if (*PRAVO == j) // ako drugi proces ima prednost
		{
			printf("(!) Proces %d mora cekati jer proces %d ima pravo\n", i, j);
			ZASTAVICA[i] = 0;		// izbaci proces koji ima manju prednost i daj prednost drugom procesu
			while (*PRAVO == j) // cekaj dok drugi proces ne zavrsi
			{
			}
			printf("(!) Proces %d ponovno pokusava uci u kriticni odsjecak\n", i);
			ZASTAVICA[i] = 1; // zatim nastavimo s procesom koji je imao manju prednost kako bi zavrsio svoj posao
		}
	}
}

void izadji_iz_kriticnog_odsjecka(int i, int j)
{
	*PRAVO = j;				// prednost dajemo drugom procesu jer je prvi zavrsio s radom
	ZASTAVICA[i] = 0; // izadji iz kriticnog odsjecka
}

// Funkcija koja ispisuje podatke na visedretven nacin
void *proc(int i)
{
	printf("(!) Proces %d pokusava uci u kriticni odsjeck\n", i);
	for (int k = 1; k <= 5; k++)
	{
		udji_u_kriticni_odsječak(i, 1 - i);
		printf("(!) Proces %d uspjesno usao u kriticni odsjeck, zapocinje obradu...\n", i);
		for (int m = 1; m <= 5; m++)
		{
			// odradi neki posao
			*suma += 1;
			printf("[%d]: suma = %d (k = %d, m = %d)\n", i, *suma, k, m);
			// sleep(1);
		}
		printf("(!) Proces %d izlazi iz kriticnog odsjecka\n", i);
		izadji_iz_kriticnog_odsjecka(i, 1 - i);
	}
}

int main()
{
	SHMID = shmget(IPC_PRIVATE, sizeof(int) * 4, 0600); // stvori zajednicku memoriju - potrebno je zauzeti prostor za 3 varijable (PRAVO, ZASTAVICA[0], ZASTAVICA[1])

	if (SHMID == -1)
	{
		perror("shmget");
		exit(1);
	}

	int *shared_memory = (int *)shmat(SHMID, NULL, 0); // pristupi zajednickoj memoriji

	suma = shared_memory;					 // varijabla suma se cita iz prvog polja zajednicke memorije
	PRAVO = shared_memory + 1;		 // varijabla PRAVO se cita iz prvog polja zajednicke memorije
	ZASTAVICA = shared_memory + 2; // varijabla ZASTAVICA se cita iz drugog polja zajednicke memorije (ZASTAVICA je pointer, pa se ovdje postavlja na adresu prvog elementa)

	*PRAVO = 0; // inicijaliziraj varijablu PRAVO na 0 - prvi proces ima prednost
	for (int i = 0; i < N; i++)
	{
		ZASTAVICA[i] = 0; // inicijaliziraj svako polje varijable ZASTAVICA na 0
	}

	if (fork() == 0)
	{
		proc(0);
		exit(0);
	}

	if (fork() == 0)
	{
		proc(1);
		exit(0);
	}

	wait(NULL);
	wait(NULL);

	shmdt(PRAVO);			// oslobodi zajednicku memoriju
	shmdt(ZASTAVICA); // oslobodi zajednicku memoriju

	shmctl(SHMID, IPC_RMID, NULL); // obrisi zajednicku memoriju

	exit(0);

	return 0;
}