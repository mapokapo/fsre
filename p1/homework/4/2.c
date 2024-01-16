#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 2. - Napisati program koji unosi znakove sve dok se ne unese veliko slovo engleskog alfabeta,
	a zatim u funkciji ispis() ispisuje broj ponavljanja svakog od samoglasnika. 
*/

void ispis(char znakovi[128], int broj_znakova) {
	char samoglasnici[5] = { 'a', 'e', 'i', 'o', 'u' };
	int broj_samoglasnika[5] = { 0, 0, 0, 0, 0 };
	int i;

	for (i = 0; i < broj_znakova; i++) {
		switch(znakovi[i]) {
			case 'a':
			case 'A':
				broj_samoglasnika[0]++;
				break;
			case 'e':
			case 'E':
				broj_samoglasnika[1]++;
				break;
			case 'i':
			case 'I':
				broj_samoglasnika[2]++;
				break;
			case 'o':
			case 'O':
				broj_samoglasnika[3]++;
				break;
			case 'u':
			case 'U':
				broj_samoglasnika[4]++;
				break;
		}
	}

	printf("Unijeli ste sljedeci broj samoglasnika:\n");
	for (i = 0; i < 5; i++) {

		printf("\t- %c = %d\n", samoglasnici[i], broj_samoglasnika[i]);
	}
}

int main() {
	char znakovi[128];
	char znak;
	int i;
	int broj_znakova = 0;

	i = 0;
	do {
		if (broj_znakova >= 128) {
			printf("Unijeli ste previse znakova!\n");
			return 0;
		}

		printf("Unesi znak: ");
		scanf(" %c", &znak);

		znakovi[i] = znak;

		i++;
		broj_znakova++;
	} while(!(znak > 'A' && znak < 'Z'));

	ispis(znakovi, broj_znakova);

	return 0;
}