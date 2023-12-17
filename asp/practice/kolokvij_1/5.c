#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f;
	char red[256];
	char *token;
	int *niz1d = NULL;
	int **niz2d = NULL;
	int *broj_stupaca_po_retku = NULL;
	int broj_redaka, broj_stupaca, ukupan_broj, i, j;

	f = fopen("UlazZaDvodimenzionalnoPolje.txt", "r");

	ukupan_broj = 0;
	broj_redaka = 0;
	while (fgets(red, 256, f) != NULL)
	{
		broj_stupaca_po_retku = realloc(broj_stupaca_po_retku, sizeof(int) * (broj_redaka + 1));
		niz2d = realloc(niz2d, sizeof(int *) * (broj_redaka + 1));
		niz2d[broj_redaka] = NULL;

		token = strtok(red, " ");

		broj_stupaca = 0;
		while (token != NULL)
		{
			niz1d = realloc(niz1d, sizeof(int) * (broj_stupaca + ukupan_broj + 1));
			niz1d[broj_stupaca + ukupan_broj] = atoi(token);

			niz2d[broj_redaka] = realloc(niz2d[broj_redaka], sizeof(int) * (broj_stupaca + 1));
			niz2d[broj_redaka][broj_stupaca] = atoi(token);

			broj_stupaca++;

			token = strtok(NULL, " ");
		}
		broj_stupaca_po_retku[broj_redaka] = broj_stupaca;

		ukupan_broj += broj_stupaca;

		broj_redaka++;
	}

	printf("1D polje: ");
	for (i = 0; i < ukupan_broj; i++)
	{
		printf("%d ", niz1d[i]);
	}
	printf("\n");

	printf("2D polje:\n");
	for (i = 0; i < broj_redaka; i++)
	{
		j = 0;
		for (j = 0; j < broj_stupaca_po_retku[i]; j++)
		{
			printf("%d ", niz2d[i][j]);
		}
		printf("\n");
	}

	return 0;
}