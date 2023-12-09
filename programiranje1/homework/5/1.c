#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 1. - Napisati program koji u funkciji unos() unosi 30 cijelih brojeva, a zatim u jednoj funkciji
	statistika() računa minimum i maksimum unesenih brojeva te ih ispisuje u glavnom programu.
*/

void unos(int brojevi[30]) {
	int i;
	
	for (i = 0; i < 30; i++) {
		printf("Unesite cijeli broj: ");
		scanf("%d", &brojevi[i]);
	}
}

void statistika(int brojevi[30]) {
	int min = brojevi[0], max = brojevi[0];
	int i;

	for (i = 0; i < 30; i++) {
		if (brojevi[i] > max) {
			max = brojevi[i];
		}
		if (brojevi[i] < min) {
			min = brojevi[i];
		}
	}

	printf("Najveci broj je %d, a najmanji %d.\n", max, min);
}

int main() {
	int brojevi[30];

	unos(brojevi);
	statistika(brojevi);

	return 0;
}