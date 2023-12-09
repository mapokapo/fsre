#include <stdio.h>
#include <string.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 3. - Napisati program koji unosi 20 realnih brojeva i ispisuje one čiji cijeli dio nije barem 100
	puta veći od njihovog decimalnog dijela. 
*/

int main() {
	/*
		brojevi - niz unesenih brojeva
		i - brojac
		broj_brojeva - kolicina unesenih brojeva
	*/
	double brojevi[20];
	int i;
	int broj_brojeva = 0;
	
	i = 0;
	do {
		printf("Unesite realni broj: ");
		scanf("%lf", &brojevi[i]);

		i++;
		broj_brojeva++;
	} while(broj_brojeva < 2);

	for (i = 0; i < broj_brojeva; i++) {
		int cijeli_dio = (int) brojevi[i];
		double decimalni_dio = brojevi[i] - cijeli_dio;

		if (cijeli_dio < decimalni_dio * 100) {
			printf("Broj %lf ima cijeli dio koji nije bar 100 puta veci od njegovog decimalnog dijela.\n", brojevi[i]);
		}
	}

	return 0;
}