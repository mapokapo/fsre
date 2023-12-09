/*
	Leo Petrovic 2174/RR

	Zadatak 4. - Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog
	pohranjuje ih u dinamički alociran memorijski prostor odgovarajuće duljine. Nakon što
	su svi znakovi pročitani, ispisuje se onaj znak koji se ponovio najviše puta, kao i broj
	njegovih ponavljanja.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *stream;
	char *znakovi = NULL, najcesci_znak;
	int i, j, broj_znakova, broj_ponavljanja_najcesceg;

	stream = fopen("tekst.txt", "r");
	if (stream == NULL)
	{
		printf("Datoteka nije pronadjena.\n");
		return 1;
	}

	broj_znakova = 0;
	while (!feof(stream))
	{
		znakovi = realloc(znakovi, sizeof(char) * (broj_znakova + 1));
		znakovi[broj_znakova] = fgetc(stream);

		broj_znakova++;
	}
	fclose(stream);

	najcesci_znak = znakovi[0];
	broj_ponavljanja_najcesceg = 0;
	for (i = 0; i < broj_znakova; i++)
	{
		int broj_ponavljanja = 0;

		for (j = 0; j < broj_znakova; j++)
		{
			if (znakovi[i] == znakovi[j])
			{
				broj_ponavljanja++;
			}
		}

		if (broj_ponavljanja > broj_ponavljanja_najcesceg)
		{
			najcesci_znak = znakovi[i];
			broj_ponavljanja_najcesceg = broj_ponavljanja;
		}
	}

	printf("Najcesci znak je %c, i ponovio se %d puta.\n", najcesci_znak, broj_ponavljanja_najcesceg);

	free(znakovi);

	return 0;
}