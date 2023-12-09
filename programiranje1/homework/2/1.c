#include <stdio.h>

/*
	Leo Petrovic - 2174/RR
	Zadatak 1:

	Napisati program koji za uneseni prirodni broj ispisuje poruku radi li se o složenom broju,
	te ako se radi o složenom broju (broju koji nije prost) i koji je njegov najveći djelitelj (a da
	nije sam taj broj, npr. djelitelji broja 18 su 1, 2, 3, 6, 9, i 18 pa je najveći djelitelj koji nije
	sam broj 18, broj 9).
*/
int main() {
	/*
		i 				brojac, koristi se vise puta
		broj 			sam broj koji unosimo
		prost			boolean (1 ili 0) koji oznacava je li broj prost
		faktori 		faktori broja, moze sadrzavati samo 128 elemenata pa se faktori prestanu unosit poslije toga
		broj_faktora	broj faktora, takodjer se koristi kao brojac za niz faktori
		max 			najveci faktor
	*/
	int i;
	int broj;
	int prost = 1;
	int faktori[128];
	int broj_faktora = 0;
	int max;

	printf("Unesi broj: ");
	scanf("%d", &broj);

	/* Provjeravamo je li broj prirodan (brojevi nakon decimalne tocke se svakako odbacuju) */
	if (broj < 1) {
		printf("Morate unijeti prirodan broj.\n");
		return 0;
	}

	/* Provjeravamo je li broj prost ili ne */
	i = 2;
	do {
		/* Rucno zaobici broj 2 jer je brojac po default-u broj 2 */
		if (broj != 2 && broj % i == 0) {
			prost = 0;
			break;
		}
		i++;
	/* Ne moramo provjeravati brojeve dalje od broj/2 */
	} while (i < broj/2);

	if (prost) {
		printf("Broj %d je prost.\n", broj);
	} else {
		i = 1;
		do {
			/* Ukljucujemo 1 u faktore ali ne ukljucujemo sam broj */
			if (broj % i == 0 && broj_faktora < 128) {
				faktori[broj_faktora] = i;
				broj_faktora++;
			}
			i++;
		} while (i < broj);

		printf("Najveci djelitelj broja %d je ", broj);
		/* Trazenje najveceg faktora */
		max = faktori[0];
		for (i = 0; i < broj_faktora; i++) {
			if (faktori[i] > max) {
				max = faktori[i];
			}
		}
		printf("%d\n", max);
	}

	return 0;
}