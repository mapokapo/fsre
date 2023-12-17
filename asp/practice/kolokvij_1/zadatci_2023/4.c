#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *funkcija(int n)
{
	int *niz, i;

	niz = malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			niz[i] = 1;
		}
		else
		{
			niz[i] = 0;
		}
	}

	return niz;
}

int main()
{
	int n, *niz, i;

	printf("Unesite velicinu niza: ");
	scanf("%d", &n);

	niz = funkcija(n);

	printf("Niz:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d", niz[i]);
		if (i < n - 1)
		{
			printf(" ");
		}
	}
	printf("\n");

	free(niz);

	return 0;
}