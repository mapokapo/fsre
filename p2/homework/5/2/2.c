/*
	Leo Petrovic - 2174/RR

	Zadatak 2. - Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese broj 0. Nakon
	svakog unosa broj se smješta u datoteku uneseni_brojevi.txt. Nakon toga u datoteku
	sortirani_neparni_brojevi.txt pohranjuju se uneseni neparni brojevi sortirani po veličini.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int *cijeli_brojevi = NULL, broj_brojeva, i, j, temp;
	FILE *stream;

	stream = fopen("uneseni_brojevi.txt", "w");
	broj_brojeva = 0;
	do
	{
		cijeli_brojevi = realloc(cijeli_brojevi, sizeof(int) * (broj_brojeva + 1));

		printf("Unesite cijeli broj: ");
		scanf("%d", &cijeli_brojevi[broj_brojeva]);

		fprintf(stream, "%d ", cijeli_brojevi[broj_brojeva]);

		broj_brojeva++;
	} while (cijeli_brojevi[broj_brojeva - 1] != 0);
	fclose(stream);

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

	stream = fopen("sortirani_neparni_brojevi.txt", "w");
	for (i = 0; i < broj_brojeva; i++)
	{
		if (cijeli_brojevi[i] % 2 == 1)
		{
			fprintf(stream, "%d\n", cijeli_brojevi[i]);
		}
	}
	fclose(stream);

	free(cijeli_brojevi);

	return 0;
}