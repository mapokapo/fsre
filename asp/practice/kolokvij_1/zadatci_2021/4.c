#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int *matrica(int n)
{
	int *matrica, i, j;

	matrica = malloc(sizeof(int) * n * n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				*(matrica + i * n + j) = 1;
			}
			else
			{
				*(matrica + i * n + j) = 0;
			}
		}
	}

	return matrica;
}

int main()
{
	char buffer[256];
	int n, i, j;
	int *m;

	printf("Unesite dimenziju: ");
	fgets(buffer, 256, stdin);
	sscanf(buffer, "%d", &n);

	m = matrica(n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", *(m + i * n + j));
			if (j < n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	free(m);

	return 0;
}