/*
	Leo Petrovic - 2174/RR

	Zadatak 4. - Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog
	znaka ispisuje, sortirane po abecedi sva do tada učitana slova. Na kraju se ispisuje broj
	ponavljanja svakog od samoglasnika (ne vodeći računa radi li se o velikim i malim
	slovima).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ispisi_sortirana(char *slova, int broj_slova)
{
	int i, j;
	char temp;

	for (i = 0; i < broj_slova - 1; i++)
	{
		for (j = i + 1; j < broj_slova; j++)
		{
			if (slova[i] > slova[j])
			{
				temp = slova[i];
				slova[i] = slova[j];
				slova[j] = temp;
			}
		}
	}

	printf("Sva ucitana slova poredana po abecedi:\n");
	for (i = 0; i < broj_slova; i++)
	{
		if (isalpha(slova[i]))
		{
			printf(" - %c\n", slova[i]);
		}
	}
}

const char samoglasnici[5] = {'a', 'e', 'i', 'o', 'u'};

void izracunaj_broj_ponavljanja_samoglasnika(char slovo, int broj_ponavljanja_samoglasnika[5])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (tolower(slovo) == samoglasnici[i])
		{
			broj_ponavljanja_samoglasnika[i]++;
		}
	}
}

int main()
{
	FILE *stream;
	char *slova = NULL, slovo;
	int i, broj_slova, broj_ponavljanja_samoglasnika[5] = {0};

	stream = fopen("./4/tekst.txt", "r");
	if (!stream)
	{
		printf("Datoteka nije pronadjena.\n");
		return 1;
	}

	broj_slova = 0;
	while (!feof(stream))
	{
		slovo = fgetc(stream);

		if (slovo != EOF)
		{
			slova = realloc(slova, sizeof(char) * (broj_slova + 1));
			slova[broj_slova] = slovo;

			ispisi_sortirana(slova, broj_slova + 1);
			izracunaj_broj_ponavljanja_samoglasnika(slovo, broj_ponavljanja_samoglasnika);

			broj_slova++;
		}
	}
	fclose(stream);

	printf("Broj ponavljanja svakog samoglasnika:\n");
	for (i = 0; i < 5; i++)
	{
		printf(" - %c = %d\n", samoglasnici[i], broj_ponavljanja_samoglasnika[i]);
	}

	free(slova);

	return 0;
}