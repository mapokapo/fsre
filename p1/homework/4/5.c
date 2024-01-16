#include <stdio.h>
#include <stdlib.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 5. - Napisati program koji unosi pet cijelih broja i u funkciji srednji() pronalazi onog koji je
	srednji po veličini te ga ispisuje u funkciji ispis(). 
*/

int srednji(int brojevi[5]) {
	float prosjek;
	int suma = 0;
	int najblizi = brojevi[0];
	int i;

	for (i = 0; i < 5; i++) {
		suma += brojevi[i];
	}

	prosjek = (float) suma / 5;

	for (i = 0; i < 5; i++) {
		if (abs(brojevi[i] - prosjek) < abs(najblizi - prosjek)) {
			najblizi = brojevi[i];
		}
	}

	return najblizi;
}

void ispis(int broj) {
	printf("Broj srednji po velicini je %d.\n", broj);
}

int main() {
	int brojevi[5];
	int i;

	i = 0;
	do {
		printf("Unesite cijeli broj: ");
		scanf("%d", &brojevi[i]);

		i++;
	} while (i < 5);

	ispis(srednji(brojevi));

	return 0;
}