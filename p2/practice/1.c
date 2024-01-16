#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Zadatak: Napisati program koji sortira niz stringova silazno. Sortiranje se vrši po abecednom redu, ne po ASCII kodovima.
*/

int main() {
	char niz[10][32];
	int i, j, k;
	char temp[32];
	
	for (i = 0; i < 10; i++) {
		printf("Unesite %d. string: ", i + 1);
		scanf("%s", niz[i]);
	}
	
	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 10; j++) {
			char prviStringMalaSlova[32];
			for (k = 0; k < strlen(niz[i]); k++) {
				prviStringMalaSlova[k] = tolower((int) niz[i][k]);
			}
			char drugiStringMalaSlova[32];
			for (k = 0; k < strlen(niz[j]); k++) {
				drugiStringMalaSlova[k] = tolower((int) niz[j][k]);
			}
			if (strcmp(prviStringMalaSlova, drugiStringMalaSlova) < 0) {
				strcpy(temp, niz[i]);
				strcpy(niz[i], niz[j]);
				strcpy(niz[j], temp);
			}
		}
	}
	
	printf("Sortirani niz: \n");
	for (i = 0; i < 10; i++) {
		printf("%s\n", niz[i]);
	}
	
	return 0;
}