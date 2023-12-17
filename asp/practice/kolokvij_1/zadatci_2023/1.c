#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char mbr[14 + 1];
	char ime[20 + 1];
	char prezime[20 + 1];
} Djelatnik;

Djelatnik *DohvatiVodeceZapise(FILE *f) {}

int main()
{
	FILE *f;
	Djelatnik *vodeci_zapisi = NULL;
	int broj_zapisa, broj_blokova, velicina_bloka, i;

	f = fopen("djelatnici.dat", "rb");
	if (f == NULL)
	{
		printf("Datoteka 'djelatnici.dat' nije pronadjena!\n");
		return 1;
	}

	fseek(f, 0, SEEK_END);
	broj_zapisa = ftell(f) / sizeof(Djelatnik);
	fseek(f, 0, SEEK_SET);

	velicina_bloka = ceil(sqrt(broj_zapisa));
	broj_blokova = ceil((float)broj_zapisa / velicina_bloka);

	for (i = 0; i < broj_blokova; i++)
	{
		vodeci_zapisi = realloc(vodeci_zapisi, sizeof(Djelatnik) * (i + 1));

		fseek(f, i * velicina_bloka * sizeof(Djelatnik), SEEK_SET);
		fread(vodeci_zapisi + i, sizeof(Djelatnik), 1, f);
	}

	printf("Vodeci zapisi:\n");
	for (i = 0; i < broj_blokova; i++)
	{
		printf("[%d] %s %s %s\n", i, vodeci_zapisi[i].mbr, vodeci_zapisi[i].ime, vodeci_zapisi[i].prezime);
	}

	return 0;
}