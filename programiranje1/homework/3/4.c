#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 4. - Napisati program koji unosi znakove sve dok se ne unese znak 'x' i zatim ih ispisuje tako
	da svaki znak koji nije slovo zamijeni njegovim ASCII kodom. Slova ispisuje onako kako su
	unesena.
*/

int main() {
	/*
		znakovi - niz unesenih znakova
		i - brojac
		broj_znakova - ukupni broj unesenih znakova
	*/
	char znakovi[128];
	int i;
	int broj_znakova = 0;

	i = 0;
	do {
		if (broj_znakova >= 128) {
			printf("Unijeli ste previse znakova.\n");
			return 0;
		}

		printf("Unesite znak: ");
		scanf(" %c", &znakovi[i]);

		i++;
		broj_znakova++;
	} while(znakovi[broj_znakova - 1] != 'x');

	for (i = 0; i < broj_znakova; i++) {
		if (znakovi[i] >= 'a' && znakovi[i] <= 'z' || znakovi[i] >= 'A' && znakovi[i] <= 'Z') {
			printf("%c\n", znakovi[i]);
		} else {
			printf("%d\n", znakovi[i]);
		}
	}

	return 0;
}