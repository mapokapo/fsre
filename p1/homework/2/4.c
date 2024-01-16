#include <stdio.h>

/*
	Leo Petrovic - 2174/RR
	Zadatak 4:

	Napisati program koji unosi 20 slova engleskog alfabeta (velikih ili malih, zanemarujući
	ostale unesene znakove). Program ispisuje broj velikih i broj unesenih malih slova.
*/
int main() {
	char slova[20];
	char znak;
	int broj_malih = 0;
	int broj_velikih = 0;
	int i;

	i = 0;
	do {
		printf("Unesi znak: ");
		/* Razmak se stavlja prije %c da bi se izbjegao whitespace tokom stiskanja tipke enter */
		scanf(" %c", &znak);
		/* Provjeravamo je li uneseni znak slovo iz engleskog alfabeta */
		if (znak >= 'a' && znak <= 'z' || znak >= 'A' && znak <= 'Z') {
			slova[i] = znak;
			if (znak >= 'a' && znak <= 'z') broj_malih++;
			if (znak >= 'A' && znak <= 'Z') broj_velikih++;
			i++;
		}

	} while (i < 20);
	
	printf("Unijeli ste %d malih i %d velikih slova.\n", broj_malih, broj_velikih);

	return 0;
}