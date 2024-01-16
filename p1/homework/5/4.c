#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 4. - Napisati program koji unosi cijeli broj i rekurzivnom funkcijom ima_li_5() provjerava je li
	neka od njegovih znamenki 5. Rezultat se ispisuje u glavnom programu.
*/

int ima_li_5(int broj) {
	int zadnja_znamenka = broj % 10;
	if (zadnja_znamenka == 5) {
		return 1;
	} else if (broj < 10) {
		return 0;
	} else {
		return ima_li_5(broj / 10);
	}
}

int main() {
	int broj;

	printf("Unesite cijeli broj: ");
	scanf("%d", &broj);

	if (ima_li_5(broj)) {
		printf("Broj %d sadrzi znamenku 5 u sebi.\n", broj);
	} else {
		printf("Broj %d ne sadrzi znamenku 5 u sebi.\n", broj);
	}

	return 0;
}