#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	FILE *f;
	int temp_broj, broj_redaka, i, j;
	int *ulazni_niz = NULL;
	int **izlazni_niz = NULL;

	f = fopen("data.txt", "r");
	if (f == NULL)
	{
		printf("Datoteka 'data.txt' nije pronadjena!\n");
		return 1;
	}

	broj_redaka = 0;
	while (fscanf(f, "%d", &temp_broj) == 1)
	{
		ulazni_niz = realloc(ulazni_niz, sizeof(int) * (broj_redaka + 1));
		ulazni_niz[broj_redaka] = temp_broj;

		broj_redaka++;
	}

	fclose(f);

	izlazni_niz = malloc(sizeof(int *) * broj_redaka);
	for (i = 0; i < broj_redaka; i++)
	{
		izlazni_niz[i] = malloc(sizeof(int) * broj_redaka);
		for (j = 0; j < broj_redaka; j++)
		{
			izlazni_niz[i][j] = pow(ulazni_niz[j], i + 1);
		}
	}

	for (i = 0; i < broj_redaka; i++)
	{
		for (j = 0; j < broj_redaka; j++)
		{
			printf("%d", izlazni_niz[i][j]);
			if (j < broj_redaka - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}