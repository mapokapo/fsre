#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 5. - Napisati program koji unosi 10 znakova u niz znak[10] i rekurzivnom funkcijom
	je_li_sortiran() provjerava je li niz silazno sortiran. Rezultat se ispisuje u glavnom
	programu. 
*/

int je_li_sortiran(char znakovi[], int duzina_niza) {
	if (duzina_niza == 0 || duzina_niza == 1) {
		return 1;
	}

	if (znakovi[duzina_niza - 1] > znakovi[duzina_niza - 2]) {
		return 0;
	}

	return je_li_sortiran(znakovi, duzina_niza - 1);
}

int main() {
	char znak[10];
	int i;

	for (i = 0; i < 10; i++) {
		printf("Unesite znak: ");
		scanf(" %c", &znak[i]);
	}

	if (je_li_sortiran(znak, 10)) {
		printf("Rijec %s je sortirana silazno.\n", znak);
	} else {
		printf("Rijec %s nije sortirana silazno.\n", znak);
	}

	return 0;
}