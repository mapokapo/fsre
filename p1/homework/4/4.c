#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 4. - Napisati program koji unosi 20 znakova i u funkciji ispis() ispisuje samo one znakove koji
	nisu slova engleskog alfabeta. 
*/

void ispis(char znakovi[20]) {
	int i;

	for (i = 0; i < 20; i++) {
		char z = znakovi[i];
		if ((z < 'a' || z > 'z') && (z < 'A' || z > 'Z')) {
			printf("Znak %c ne pripada engleskom alfabetu.\n", z);
		}
	}
}

int main() {
	char znakovi[20];
	int i;

	i = 0;
	do {
		printf("Unesite znak: ");
		scanf(" %c", &znakovi[i]);

		i++;
	} while (i < 20);

	ispis(znakovi);

	return 0;
}