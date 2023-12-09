/*
	Leo Petrovic - 2174/RR

	Zadatak 1. - Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjereni
	vodostaji (realni brojevi) na određenom mjernom mjestu tijekom vremena. Pročitati sve
	vodostaje i odrediti prosječan vodostaj na tom mjernom mjestu.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *naziv_datoteke, buffer[256];
	float *vodostaji = NULL, zbroj_vodostaja;
	int i, broj_linija;
	FILE *stream;

	printf("Unesite naziv datoteke: ");
	fgets(buffer, 256, stdin);
	naziv_datoteke = malloc(sizeof(char) * strlen(buffer) + 1);
	sscanf(buffer, "%s", naziv_datoteke);

	stream = fopen(naziv_datoteke, "r");
	free(naziv_datoteke);
	if (!stream)
	{
		printf("Datoteka nije pronadjena.\n");
		return 1;
	}

	broj_linija = 0;
	while (!feof(stream))
	{
		vodostaji = realloc(vodostaji, sizeof(float) * (broj_linija + 1));
		fscanf(stream, "%f", &vodostaji[broj_linija]);
		broj_linija++;
	}
	fclose(stream);

	zbroj_vodostaja = 0;
	for (i = 0; i < broj_linija; i++)
	{
		zbroj_vodostaja += vodostaji[i];
	}

	free(vodostaji);

	printf("Prosjecni vodostaj je: %.2f\n", zbroj_vodostaja / broj_linija);

	return 0;
}