/*
	Leo Petrovic, 2174/RR

	Zadatak 2. - Napisati program koji dinamički zauzima memoriju za 20 stringova maksimalne duljine
	od 20 znakova, unosi stringove, sortira ih po duljini silazno, odnosno po abecedi (ako je
	duljina ista) te ih ispisuje. Koristiti isključivo sintaksu pokazivača.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DULJINA_NIZA 5

int main()
{
	char **niz_stringova, *temp;
	int i, j;

	temp = malloc(sizeof(char) * 20);

	niz_stringova = malloc(sizeof(char *) * DULJINA_NIZA); // N elemenata (pointera)
	for (i = 0; i < DULJINA_NIZA; i++)
	{
		*(niz_stringova + i) = malloc(sizeof(char) * 20); // 20 znakova za svaki pointer (20 slova za svaki string)
	}

	for (i = 0; i < DULJINA_NIZA; i++)
	{
		printf("Unesite %d. string: ", i + 1);
		fflush(stdin);
		gets(*(niz_stringova + i));
	}

	for (i = 0; i < DULJINA_NIZA - 1; i++)
	{
		for (j = i + 1; j < DULJINA_NIZA; j++)
		{
			if (strlen(*(niz_stringova + i)) == strlen(*(niz_stringova + j)) && strcmp(*(niz_stringova + i), *(niz_stringova + j)) > 0 || strlen(*(niz_stringova + i)) < strlen(*(niz_stringova + j)))
			{
				strcpy(temp, *(niz_stringova + i));
				strcpy(*(niz_stringova + i), *(niz_stringova + j));
				strcpy(*(niz_stringova + j), temp);
			}
		}
	}

	for (i = 0; i < DULJINA_NIZA; i++)
	{
		printf("%d. string: %s\n", i + 1, *(niz_stringova + i));
	}

	return 0;
}