#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char mbr[20 + 1];
	char ime[20 + 1];
	char prezime[20 + 1];
} osoba;

int trazi_element(osoba polje[], int n, char *mbr)
{
	int min, max, mid;
	osoba pom;

	min = 0;
	max = n - 1;

	while (min <= max)
	{
		mid = ceil((float)(min + max) / 2);

		pom = polje[mid];

		printf("[%d-%d, %d] %s %s %s\n", min, max, mid, pom.mbr, pom.ime, pom.prezime);
		if (strcmp(pom.mbr, mbr) < 0)
		{
			min = mid + 1;
		}
		else if (strcmp(pom.mbr, mbr) > 0)
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
	osoba pom, *svi = NULL;
	int broj_osoba, i;

	f = fopen("djelatnici_mbr.dat", "rb");
	if (f == NULL)
	{
		printf("Datoteka 'djelatnici_mbr.dat' nije pronadjena!\n");
		return 1;
	}

	broj_osoba = 0;
	while (fread(&pom, sizeof(osoba), 1, f))
	{
		svi = realloc(svi, sizeof(osoba) * (broj_osoba + 1));
		svi[broj_osoba] = pom;

		broj_osoba++;
	}

	for (i = 0; i < broj_osoba; i++)
	{
		if (trazi_element(svi, broj_osoba, svi[i].mbr))
		{
			printf("Postoji mbr '%s'\n", svi[i].mbr);
		}
		else
		{
			printf("Ne postoji mbr '%s'\n", svi[i].mbr);
		}
	}

	return 0;
}