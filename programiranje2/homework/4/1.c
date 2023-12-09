/*
	Leo Petrovic, 2174/RR

	Zadatak 1. - Napisati program koji pita korisnika kolika je dimenzija niza cijelih brojeva, dinamički
	alocira memoriju za taj niz i unosi brojeve, a zatim unosi i dodatni cijeli broj u također
	dinamički alociranu memoriju te na kraju ispisuje, sortiran po veličini, samo one brojeve
	iz niza koji su veći od dodanog broja. Koristiti isključivo sintaksu pokazivača.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *niz, *dodatni_broj;
	int duljina_niza, i, j;

	printf("Unesite duljinu niza: ");
	scanf("%d", &duljina_niza);

	niz = (int *)malloc(sizeof(int) * duljina_niza);

	for (i = 0; i < duljina_niza; i++)
	{
		printf("Unesite %d. broj: ", i + 1);
		scanf("%d", niz + i);
	}

	dodatni_broj = (int *)malloc(sizeof(int));
	printf("Unesi dodatni broj: ");
	scanf("%d", dodatni_broj);

	for (i = 0; i < duljina_niza - 1; i++)
	{
		for (j = i + 1; j < duljina_niza; j++)
		{
			if (*(niz + i) > *(niz + j))
			{
				int temp = *(niz + i);
				*(niz + i) = *(niz + j);
				*(niz + j) = temp;
			}
		}
	}

	printf("Brojevi koji su veci od dodatnog broja:\n");
	for (i = 0; i < duljina_niza; i++)
	{
		if (*(niz + i) > *dodatni_broj)
		{
			printf(" - %d\n", *(niz + i));
		}
	}

	return 0;
}