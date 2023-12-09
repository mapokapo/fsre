#include <stdio.h>
#include <stdlib.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 3. - Napisati program koji u funkciji unos() unosi 20 cijelih brojeva, u funkciji
	aritmeticka_sredina() računa njihovu aritmetičku sredinu, a u funkciji najdalji()
	pronalazi uneseni broj najdalji prosjeku. Rezultati se ispisuju u glavnom programu.
*/

int unos() {
	int broj;

	printf("Unesite cijeli broj: ");
	scanf("%d", &broj);

	return broj;
}

float aritmeticka_sredina(int brojevi[20]) {
	int suma = 0;
	int i;

	for (i = 0; i < 20; i++) {
		suma += brojevi[i];
	}

	return (float) suma / 20;
}

int najdalji(int brojevi[20], float prosjek) {
	int najdalji = brojevi[0];
	int i;

	for (i = 0; i < 20; i++) {
		if (abs(brojevi[i] - prosjek) > abs(najdalji - prosjek)) {
			najdalji = brojevi[i];
		}
	}

	return najdalji;
}

int main() {
	int brojevi[20];
	int i = 0;

	do {
		brojevi[i] = unos();

		i++;
	} while (i < 20);

	printf("Prosjek: %f\n", aritmeticka_sredina(brojevi));
	printf("Broj najdalji od prosjeka: %d\n", najdalji(brojevi, aritmeticka_sredina(brojevi)));
}