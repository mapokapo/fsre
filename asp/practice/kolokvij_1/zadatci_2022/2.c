#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rekurzivna_suma(int niz[], int n)
{
	if (n <= 0)
		return 0;

	return niz[n - 1] + rekurzivna_suma(niz, n - 1);
}

int main()
{
	int *niz = NULL, suma;
	int temp, kontrola;
	int broj_elemenata, i, j, br;
	broj_elemenata = 0;
	do
	{
		printf("Unesite element: ");

		scanf("%d", &temp);
		kontrola = 1;
		if (temp != 0)
		{
			for (i = 0; i < broj_elemenata; i++)
			{
				/*for (j = 0; j < broj_elemenata; j++)
				{

				}*/
				if (niz != NULL && broj_elemenata > 0 && niz[i] == temp)
				{
					kontrola = 0;
				}
			}
		}
		if (kontrola && temp != 0)
		{
			// if (kontrola) {
			// niz[broj_elemenata] = temp;
			niz = realloc(niz, sizeof(int) * (broj_elemenata + 1));
			niz[broj_elemenata] = temp;
		}
		broj_elemenata++;
	} while (temp != 0);

	suma = rekurzivna_suma(niz, broj_elemenata);
	printf("Suma je: %d\n", suma);

	return 0;
}