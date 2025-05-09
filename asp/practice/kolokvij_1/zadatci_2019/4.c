#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void okreni_oduzmi(int niz[], int duljina, int n)
{
	if (n > duljina)
		n = duljina;

	if (n <= 0)
		return;

	printf("%d ", niz[n - 1] - niz[0]);
	okreni_oduzmi(niz, duljina, n - 1);
}

int main()
{
	int niz[] = {2, 6, 8, 11, -3, 100};
	int duljina = 6;
	int n = 5;

	okreni_oduzmi(niz, duljina, n);
	printf("\n");

	return 0;
}