#include <stdio.h>
#include <string.h>

/*
	Zadatak: Napisati program koji broji broj rijeci u stringu, pazeci da vise razmaka izmedju rijeci ne racuna kao vise rijeci.
*/

int main() {
	char string[256];
	int i, brojRijeci = 0;
	int rijecPocela = 0;

	printf("Unesite string: ");
	fflush(stdin);
	fgets(string, 255, stdin);

	int duzinaStringa = strlen(string) - 1;

	for (i = 0; i < duzinaStringa; i++) {
		if (string[i] == ' ') {
			if (rijecPocela == 1) {
				brojRijeci++;
				rijecPocela = 0;
			}
		} else {
			rijecPocela = 1;
		}
	}

	if (rijecPocela == 1) {
		brojRijeci++;
	}

	printf("Broj rijeci u stringu je: %d\n", brojRijeci);

	return 0;
}