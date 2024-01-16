#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 1. - Napisati program koji unosi cijele brojeve sve dok se četiri puta zaredom ne unese broj
	manji od 10. Program ispisuje broj koji je unesen najviše puta.
*/

int main() {
	/*
		brojevi - niz unesenih brojeva
		broj_brojeva - ukupni broj unesenih brojeva
		i, j - brojaci
		brojac_brojeva, najveci_brojac_brojeva - kontrolne varijable koje prate koji je najcesci broj
		broj_manjih_od_10 - broj brojeva manjih od 10 za redom
		najcesci_broj - broj koji se najvise puta pojavljuje u nizu
	*/
	int brojevi[128];
	int broj_brojeva = 0;
	int i, j;
	int brojac_brojeva, najveci_brojac_brojeva;
	int broj_manjih_od_10 = 0;
	int najcesci_broj;

	i = 0;
	do {
		if (broj_brojeva >= 128) {
			printf("Unijeli ste previse brojeva.\n");
			return 0;
		}

		printf("Unesite cijeli broj: ");
		scanf("%d", &brojevi[i]);
		
		if (brojevi[i] < 10) {
			broj_manjih_od_10++;
		} else {
			broj_manjih_od_10 = 0;
		}

		i++;
		broj_brojeva++;
	} while (broj_manjih_od_10 < 4);

	najveci_brojac_brojeva = 0;
	for (i = 0; i < broj_brojeva; i++) {
		brojac_brojeva = 0;
		for (j = 0; j < broj_brojeva; j++) {
			if (brojevi[i] == brojevi[j]) {
				brojac_brojeva++;
			}
		}

		if (brojac_brojeva > najveci_brojac_brojeva) {
			najveci_brojac_brojeva = brojac_brojeva;
			najcesci_broj = brojevi[i];
		}
	}

	printf("Broj koji je najvise puta unesen je %d.\n", najcesci_broj);

	return 0;
}