#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char mbr[14 + 1];
	char ime[20 + 1];
	char prezime[20 + 1];
} zapis;

int trazi(FILE *f, char *prezime)
{
	int min, max, mid;
	zapis pom;

	min = 0;

	fseek(f, 0, SEEK_END);
	max = ftell(f) / sizeof(zapis) - 1;
	fseek(f, 0, SEEK_SET);

	while (min <= max)
	{
		mid = ceil((float)(min + max) / 2);

		fseek(f, (mid) * sizeof(zapis), SEEK_SET);
		fread(&pom, sizeof(zapis), 1, f);

		printf("[%d-%d, %d] %s %s %s\n", min, max, mid, pom.mbr, pom.ime, pom.prezime);
		if (strcmp(pom.prezime, prezime) < 0)
		{
			min = mid + 1;
		}
		else if (strcmp(pom.prezime, prezime) > 0)
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
	FILE *f;
	zapis pom, *svi = NULL;
	int broj_zapisa, i;

	f = fopen("djelatnici.dat", "rb");
	if (f == NULL)
	{
		printf("Datoteka 'djelatnici.dat' nije pronadjena!\n");
		return 1;
	}

	broj_zapisa = 0;
	while (fread(&pom, sizeof(zapis), 1, f))
	{
		svi = realloc(svi, sizeof(zapis) * (broj_zapisa + 1));
		svi[broj_zapisa] = pom;

		broj_zapisa++;
	}

	for (i = 0; i < broj_zapisa; i++)
	{
		if (trazi(f, svi[i].prezime))
		{
			printf("Postoji prezime '%s'\n", svi[i].prezime);
		}
		else
		{
			printf("Ne postoji prezime '%s'\n", svi[i].prezime);
		}
	}

	return 0;
}