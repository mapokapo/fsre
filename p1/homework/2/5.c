#include <stdio.h>

/*
	Leo Petrovic - 2174/RR
	Zadatak 5:

	Napisati program koji unosi dekadski cijeli broj dcb iz intervala [0, 255] i cijeli broj b iz
	intervala [0, 9] koji predstavlja bazu brojevnog sustava. Program ispisuje zapis dekadskog
	broja dcb u bazi b.
*/
int main() {
	/*
		dcb 						uneseni dekadski cijeli broj
		b 							baza brojevnog sustava
		rezultat 					dcb prikazan u bazi b, ima 255 mjesta da bi se najveci broj (255) mogao pokazati u najmanjoj bazi (1)
									svaka baza veca od 1 nuzno ima manje od 255 znamenki
		broj_znamenki_rezultata 	od koliko znamenki se sastoji rezultat, koristi se za ispis rezultata
		i 							brojac, koristi se vise puta
	*/
	int dcb;
	int b;
	int rezultat[255];
	int broj_znamenki_rezultata = 0;
	int i;
	
	/* Unosimo dcb i b sve dok ne dobijemo validan odgovor */
	do {
		printf("Unesite dekadski cijeli broj (od 0 do 255): ");
		scanf("%d", &dcb);
	} while (dcb < 0 || dcb > 255);
	do {
		printf("Unesite bazu (od 0 do 9): ");
		scanf("%d", &b);
	} while (b < 0 || b > 9);
	
	/* Poseban slucaj - broj se ne moze zapisati u bazi 0 */
	if (b == 0) {
		printf("Baza broja ne moze biti nula.\n");
		return 0;
	}

	printf("Broj %d iz dekadskog zapisa po bazi %d je ", dcb, b);

	/* Poseban slucaj - kada je baza 1, ispisujemo jedinice dcb puta. */
	if (b == 1) {
		for (i = 0; i < dcb; i++) {
			printf("1");
		}
		printf(".\n");
		return 0;
	}

	i = 0;
	do {
		/*
			Sukcesivno dijeljenje - dcb postavljamo na rezultat cijelobrojnog dijeljenja sa b i ponavljamo sve dok dcb ne postane nula.
			Ostatak dijeljenja nakon svakog koraka se pohranjuje u niz rezultat u obrnutom smjeru, pa ce se poslije morati ispisati u tocnom redosljedu.
		*/
		rezultat[i] = dcb % b;
		dcb /= b;
		broj_znamenki_rezultata++;
		i++;
	} while (dcb > 0);
 
	/* Prolazimo kroz niz rezultat u obrnutom smjeru da bi se pravilno dobiveni broj ispisao */
	for (i = broj_znamenki_rezultata - 1; i >= 0; i--) {
		printf("%d", rezultat[i]);
	}
	printf(".\n");

	return 0;
}