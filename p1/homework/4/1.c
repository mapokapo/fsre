#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 1. - Napisati program koji u funkciji unos() unosi 50 cijelih brojeva, a zatim u funkciji prost()
	ispisuje koliko je od unesenih brojeva prosto.
*/

int unos() {
	int broj;

	printf("Unesi broj: ");
	scanf("%d", &broj);

	return broj;
}

int prost(int broj) {
	if (broj == 0 || broj == 1) return 0;

	int i;

	for (i = 2; i <= broj / 2; i++) {
		if (broj % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int brojevi[50];
	int i;

	for (i = 0; i < 50; i++) {
		brojevi[i] = unos();
	}
	for (i = 0; i < 50; i++) {
		if (prost(brojevi[i])) {
			printf("Broj %d je prost.\n", brojevi[i]);
		} else {
			printf("Broj %d nije prost.\n", brojevi[i]);
		}
	}

	return 0;
}