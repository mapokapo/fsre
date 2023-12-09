/* Formirajte strukturu:

struct Slika
{
	char ime[20];
	char autor[20];
}

Inicijalizirajte niz od 7 takvih struktura i ispišite imena svih slika ciji je autor "Picasso", abecednim redom.*/

#include <stdio.h>
#include <string.h>

struct Slika
{
	char ime[20];
	char autor[20];
};

int main()
{
	struct Slika niz[7] = {
			{"Neka slika",
			 "Picasso"},
			{"Druga slika",
			 "Neki autor"},
			{"Mona Lisa",
			 "Leonardo da Vinci"},
			{"Slika 2",
			 "Picasso"},
			{"Slika 3",
			 "Picasso"},
			{"Vrisak",
			 "Edvard Munch"},
			{"Jos jedna slika",
			 "Picasso"}};
	int i, j;

	for (i = 0; i < 6; i++)
	{
		for (j = i + 1; j < 7; j++)
		{
			if (strcmp(niz[i].ime, niz[j].ime) > 0)
			{
				struct Slika temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

	printf("Slike od Picassa:\n");
	for (i = 0; i < 7; i++)
	{
		if (strcmp(niz[i].autor, "Picasso") == 0)
		{
			printf(" - %s\n", niz[i].ime);
		}
	}

	return 0;
}