#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 2. - Napisati program koji unosi znakove sve dok se dva puta zaredom ne unese samoglasnik
	(ne vodeći računa je li mali ili veliki), a zatim u funkciji obrada() pronalazi onaj znak koji
	je unesen najviše puta i broj njegovih ponavljanja te ih ispisuje u glavnom programu.
*/

int znak_je_samoglasnik(char znak) {
	return znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u' ||
					znak == 'A' || znak == 'E' || znak == 'I' || znak == 'O' || znak == 'U';
}

void obrada(char znakovi[], int broj_znakova) {
	char najcesci_znak;
	int max_broj_ponavljanja = 0;
	int i, j;

	for (i = 0; i < broj_znakova; i++) {
		int broj_ponavljanja = 0;
		for (j = 0; j < broj_znakova; j++) {
			if (znakovi[i] == znakovi[j]) {
				broj_ponavljanja++;
			}
		}
		if (broj_ponavljanja > max_broj_ponavljanja) {
			najcesci_znak = znakovi[i];
			max_broj_ponavljanja = broj_ponavljanja;
		}
	}

	printf("Znak koji se najvise puta ponavlja je %c (%d puta).\n", najcesci_znak, max_broj_ponavljanja);
}

int main() {
	char znakovi[128];
	int broj_znakova = 0;
	int i = 0;

	do {
		if (broj_znakova >= 128) {
			printf("Unijeli ste previse znakova!\n");
			return 0;
		}

		printf("Unesite znak: ");
		scanf(" %c", &znakovi[i]);

		i++;
		broj_znakova++;
	} while (broj_znakova < 2 || !(znak_je_samoglasnik(znakovi[broj_znakova - 1]) && znak_je_samoglasnik(znakovi[broj_znakova - 2])));

	obrada(znakovi, broj_znakova);

	return 0;
}