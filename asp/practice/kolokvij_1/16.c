#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindrom(char *str, int starti, int endi)
{
	while (!isalpha(str[starti]))
		starti++;
	while (!isalpha(str[endi]))
		endi--;

	if (tolower(str[starti]) != tolower(str[endi]))
		return 0;
	if (starti >= endi)
		return 1;

	return palindrom(str, starti + 1, endi - 1);
}

int najveci(int niz[], int n)
{
	int max, temp;

	if (n < 1)
		return -1;

	max = niz[n - 1];
	temp = najveci(niz, n - 1);

	if (temp > max)
		max = temp;

	return max;
}

int suma(int niz[], int n)
{
	if (n <= 0)
		return 0;
	return niz[n - 1] + suma(niz, n - 1);
}

int main()
{
	char buffer[256], *token;
	int *niz = NULL;
	int i, br_brojeva;

	printf("Unesite recenicu: ");
	gets(buffer);

	printf("Recenica '%s' ", buffer);
	if (palindrom(buffer, 0, strlen(buffer) - 1))
	{
		printf("jeste");
	}
	else
	{
		printf("nije");
	}
	printf(" palindrom.\n");

	printf("Unesite brojeve odvojene zarezom: ");
	gets(buffer);

	token = strtok(buffer, ",");
	br_brojeva = 0;
	while (token != NULL)
	{
		niz = realloc(niz, sizeof(int) * (br_brojeva + 1));
		niz[br_brojeva] = atoi(token);

		token = strtok(NULL, ",");

		br_brojeva++;
	}

	printf("Suma unesenih brojeva je %d.\n", suma(niz, br_brojeva));
	printf("Najveci broj je %d.\n", najveci(niz, br_brojeva));

	return 0;
}