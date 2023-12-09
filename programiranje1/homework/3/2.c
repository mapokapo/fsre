#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 2. - Napisati program koji unosi znakove sve dok se zaredom ne unesu mala slova 'e', 'n' i 'd'
	(ne računajući ENTER). Program ispisuje koliko je puta unesen svaki od samoglasnika
	(bez obzira radi li se o velikom ili malom slovu).
*/

int main() {
	/*
		slova - niz unesenih slova
		samoglasnici - niz samoglasnika (velika i mala slova)
		broj_samoglasnika - niz gdje svaki index predstavlja samoglasnik (po redu AEIOU) a vrijednosti predstavljaju koliko se taj samoglasnik puta ponavlja
		i, j - brojaci
		broj_slova - ukupni broj slova
	*/
	char slova[128];
	char samoglasnici[] = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };
	int broj_samoglasnika[] = { 0, 0, 0, 0, 0 };
	int i, j;
	int broj_slova = 0;

	i = 0;
	do {
		if (broj_slova >= 128) {
			printf("Unijeli ste previse slova.\n");
			return 0;
		}

		printf("Unesite znak: ");
		scanf(" %c", &slova[i]);

		for (j = 0; j < 10; j++) {
			if (slova[i] == samoglasnici[j]) {
				broj_samoglasnika[j / 2]++;
			}
		}

		i++;
		broj_slova++;

	} while (broj_slova < 3 || slova[broj_slova - 3] != 'e' || slova[broj_slova - 2] != 'n' || slova[broj_slova - 1] != 'd');

	printf("Broj samoglasnika koje ste unijeli: \n");
	for (i = 0; i < 5; i++) {
		printf("%c - %d\n", samoglasnici[i * 2], broj_samoglasnika[i]);
	}

	return 0;
}