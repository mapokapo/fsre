#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	Leo Petrovic - 2174/RR
	Zadatak 3:

	Napisati program koji unosi realne brojeve sve dok se dva puta zaredom ne unesu
	brojevi sa istim decimalnim dijelom (npr. 3.76 i -2.76). Program ispisuje prosjek
	pozitivnih unesenih brojeva.
*/
int main() {
	/*
		zadnji 						zadnji uneseni broj
		predzanji 					broj unesen prije zadnjeg
		brojevi						niz unesenih brojeva
		zbroj						zbroj pozitivnih brojeva, sluzi za racunanje prosjeka
		broj_brojeva 				kolicina unesenih brojeva, sluzi za racunanje prosjeka i da ne prekinemo petlju odmah ako je samo jedna nula unesena
		broj_pozitivnih_brojeva 	kolicina pozitivnih unesenih brojeva, sluzi za racunanje prosjeka
		i							brojac, koristi se vise puta
	*/
	float zadnji;
	float predzadnji;
	float brojevi[128];
	float zbroj = 0;
	int broj_brojeva = 0;
	int broj_pozitivnih_brojeva = 0;
	int i;

	i = 0;
	do {
		printf("Unesi realan broj: ");
		scanf("%f", &brojevi[i]);
		zadnji = brojevi[i];
		/* predzadnji se dodaje samo ako imamo bar 2 broja, inace bi uzimali indeks -1 od brojeva, sto nije moguce */
		if (i > 0) predzadnji = brojevi[i-1];

		broj_brojeva++;
		if (brojevi[i] >= 0) broj_pozitivnih_brojeva++;

		i++;
	/* Provjeravamo samo prva 2 decimalna mjesta (kao cijeli brojevi) da bi izbjegli pogreske u preciznosti floating-point brojeva */
	} while (broj_brojeva < 2 || (int)((fabs(zadnji) - abs(zadnji)) * 100 + .5) != (int)((fabs(predzadnji) - abs(predzadnji)) * 100 + .5));

	printf("Prosjek pozitivnih unesenih brojeva je ");
	for (i = 0; i < broj_brojeva; i++) {
		if (brojevi[i] >= 0) zbroj += brojevi[i];
	}
	printf("%.2f\n", zbroj / broj_pozitivnih_brojeva);

	return 0;
}