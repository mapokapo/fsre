#include <stdio.h>

/*
	Leo Petrovic - 2174/RR
	Zadatak 2:

	Napisati program koji unosi znakove sve dok se ne unese znak ! i ispisuje koliko je od
	unesenih znakova suglasnika, ne vodeći računa radi li se o malim ili velikim slovima.
*/
int main() {
	/*
		broj_znakova		prati koliko je ukupno znakova uneseno
		broj_suglasnika 	prati koliko je suglasnika uneseno
		znak 				trenutni znak
		i					brojac
	*/
	int broj_znakova = 0;
	int broj_suglasnika = 0;
	char znak;
	int i;

	i = 0;
	do {
		printf("Unesite znak: ");
		/* Razmak se stavlja prije %c da bi se izbjegao whitespace tokom stiskanja tipke enter */
		scanf(" %c", &znak);
		
		/* Provjeravamo je li uneseni znak suglasnik */
		switch (znak) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				broj_suglasnika++;
		}
		/* Preskacemo znak '!' */
		if (znak != '!') {
			broj_znakova++;
		}
		
		i++;
	} while (znak != '!');

	printf("Od %d unesenih znakova, %d od njih su suglasnici.\n", broj_znakova, broj_suglasnika);

	return 0;
}