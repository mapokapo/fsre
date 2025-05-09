#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sumaRekurzivno(int a[], int n)
{
	if (n <= 0)
		return 0;

	return a[n - 1] + sumaRekurzivno(a, n - 1);
}

int main()
{
	int a[10];
	int n = 10;
	int i;

	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		int num = (rand() % (200 - (-200) + 1)) + (-200);
		a[i] = num;
	}

	for (i = 0; i < n; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");

	printf("Suma brojeva je: %d.\n", sumaRekurzivno(a, n));

	return 0;
}