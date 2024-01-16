#include <stdio.h>

/*
	Leo Petrović - 2174/RR

	Zadatak 5. - Napisati program koji unosi tri prirodna broja te računa i ispisuje njihov najveći
	zajednički djelitelj (najveći prirodni broj s kojim su djeljiva sva tri unesena broja).
*/

int main() {
	/*
		brojevi - niz unesenih brojevi
		i - brojac
	*/
	int brojevi[3];
	int i;

	for (i = 0; i < 3; i++) {
		printf("Unesi broj: ");
		scanf("%d", &brojevi[i]);
	}

	// Sukcesivno dijelimo prvi broj sa drugim i ostatak ostavljamo u prvi broj, te ih u petlji zamijenimo.
	// Ovo se ponavlja dok ostatak ne postane 0.
	// Ako je drugi broj nula (sto znaci da ne mozemo dijeliti prvi broj sa njim), onda rucno postavljamo najveci dijelitelj na prvi broj.
	if (brojevi[1] == 0) {
		brojevi[1] = brojevi[0];
	} else {
		while (brojevi[0] %= brojevi[1]) {
			int temp = brojevi[0];
			brojevi[0] = brojevi[1];
			brojevi[1] = temp;
		}
	}
	// Ovo radimo 2 puta
	if (brojevi[2] == 0) {
		brojevi[2] = brojevi[1];
	} else {
		while (brojevi[1] %= brojevi[2]) {
			int temp = brojevi[1];
			brojevi[1] = brojevi[2];
			brojevi[2] = temp;
		}
	}

	printf("Najveci zajednicki djelitelj im je: %d\n", brojevi[2]);
	return 0;
}