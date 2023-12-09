/*
	Leo Petrovic 2174/RR

	Zadatak 2. - Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese prost. Nakon
	svakog unosa, brojevi se smještaju u dinamički alociran memorijski prostor odgovarajuće
	veličine. Nakon završetka unosa, brojevi se spremaju u datoteku sortirani_brojevi.txt,
	sortirani po veličini silazno.
*/

#include <stdio.h>
#include <stdlib.h>

int je_li_prost(int broj)
{
	int i;

	if (broj == 1)
	{
		return 0;
	}

	for (i = 2; i < broj; i++)
	{
		if (broj % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int *cijeli_brojevi = NULL, broj_brojeva, i, j, temp;
	FILE *stream;

	broj_brojeva = 0;
	do
	{
		cijeli_brojevi = realloc(cijeli_brojevi, sizeof(int) * (broj_brojeva + 1));

		printf("Unesite cijeli broj: ");
		scanf("%d", &cijeli_brojevi[broj_brojeva]);

		broj_brojeva++;
	} while (!je_li_prost(cijeli_brojevi[broj_brojeva - 1]));

	for (i = 0; i < broj_brojeva - 1; i++)
	{
		for (j = i + 1; j < broj_brojeva; j++)
		{
			if (cijeli_brojevi[i] < cijeli_brojevi[j])
			{
				temp = cijeli_brojevi[i];
				cijeli_brojevi[i] = cijeli_brojevi[j];
				cijeli_brojevi[j] = temp;
			}
		}
	}

	stream = fopen("sortirani_brojevi.txt", "w");
	for (i = 0; i < broj_brojeva; i++)
	{
		fprintf(stream, "%d\n", cijeli_brojevi[i]);
	}
	fclose(stream);

	free(cijeli_brojevi);

	return 0;
}