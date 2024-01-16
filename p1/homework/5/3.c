#include <stdio.h>
#include <stdlib.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 3. - Napisati program koji u funkciji unos() unosi 20 cijelih brojeva, i u funkciji par_najblizih()
	pronalazi ona dva broja koja su međusobno najbliža te ih ispisuje u glavnom programu.
*/

void unos(int brojevi[20]) {
	int i;

	for (i = 0; i < 20; i++) {
		printf("Unesite cijeli broj: ");
		scanf("%d", &brojevi[i]);
	}
}

void par_najblizih(int brojevi[20]) {
	int a = brojevi[0], b = brojevi[1];
	int i, j;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			if (i != j && abs(brojevi[i] - brojevi[j]) < abs(a - b)) {
				a = brojevi[i];
				b = brojevi[j];
			}
		}
	}

	printf("Par medjusobno najblizih brojeva su %d i %d.\n", a, b);
}

int main() {
	int brojevi[20];

	unos(brojevi);
	par_najblizih(brojevi);

	return 0;
}