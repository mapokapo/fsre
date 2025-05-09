#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char sifra[20 + 1];
	char ime_prezime[20 + 1];
} Osoba;

int trazi(Osoba lista[], int n, char *sifra)
{
	int min, max, mid;

	min = 0;
	max = n - 1;

	while (min <= max)
	{
		mid = (min + max) / 2;

		if (strcmp(lista[mid].sifra, sifra) < 0)
		{
			min = mid + 1;
		}
		else if (strcmp(lista[mid].sifra, sifra) > 0)
		{
			max = mid - 1;
		}
		else
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	Osoba lista[] = {
			{"0001", "Ivan Horvat"},
			{"0002", "Marko Markovic"},
			{"0003", "Ivana Horvat"},
			{"0004", "Mate Maric"},
			{"0005", "Pero Peric"},
			{"0006", "Jure Jurec"},
			{"0007", "Ivica Ivic"},
			{"0008", "Maja Majic"},
			{"0009", "Ana Anic"},
			{"0010", "Ante Antic"}};

	if (trazi(lista, 10, "0001"))
	{
		printf("Pronadjeno!\n");
	}
	else
	{
		printf("Nije pronadjeno!\n");
	}

	return 0;
}