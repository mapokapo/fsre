#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ispis_znamenki(char niz[], int n)
{
	int jeste_znamenka = 0;

	if (n > 0)
	{
		if (isdigit(niz[n - 1]))
		{
			printf("%c", niz[n - 1]);
			jeste_znamenka = 1;
		}

		jeste_znamenka += ispis_znamenki(niz, n - 1);
	}

	return jeste_znamenka;
}

int main()
{
	char buffer[256];
	int br;

	printf("Unesite recenicu: ");
	fgets(buffer, 256, stdin);

	br = ispis_znamenki(buffer, strlen(buffer));
	printf("\nBroj znamenki: %d\n", br);

	return 0;
}