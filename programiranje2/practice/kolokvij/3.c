/* Formirajte strukturu:

struct Mezimac
{
char ime[20];
char pasmina[20];
}

Inicijalizirajte niz od 7 takvih struktura i ispišite imena mezimaca čija je pasmina "pas" abecednim redom. */

#include <stdio.h>
#include <string.h>

struct Mezimac
{
	char ime[20];
	char pasmina[20];
};

int main()
{
	struct Mezimac niz[7] = {
			{"Rex",
			 "pas"},
			{"Jure",
			 "covjek"},
			{"Oreo",
			 "macka"},
			{"Stipe",
			 "pas"},
			{"Max",
			 "pas"},
			{"Pero",
			 "covjek"},
			{"Buba",
			 "pas"}};
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = i + 1; j < 7; j++)
		{
			if (strcmp(niz[i].ime, niz[j].ime) > 0)
			{
				struct Mezimac temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

	printf("Mezimci koji su psi:\n");
	for (i = 0; i < 7; i++)
	{
		if (strcmp(niz[i].pasmina, "pas") == 0)
		{
			printf(" - %s\n", niz[i].ime);
		}
	}

	return 0;
}