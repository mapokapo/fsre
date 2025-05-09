#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	int mbr;
	char ime[21];
	char prezime[21];
} Zapis;

int main()
{
	FILE *f;
	int br_zapisa, vel_bloka, br_blokova, i;
	Zapis temp, *lista = NULL;

	f = fopen("djelatnici.dat", "rb");
	if (f == NULL)
		return 1;

	fseek(f, 0, SEEK_END);
	br_zapisa = ftell(f) / sizeof(Zapis);
	rewind(f);

	vel_bloka = round(sqrt(br_zapisa));
	br_blokova = ceil((float)br_zapisa / vel_bloka);

	lista = malloc(sizeof(Zapis) * br_blokova);
	for (i = 0; i < br_blokova; i++)
	{
		fseek(f, i * vel_bloka * sizeof(Zapis), SEEK_SET);
		fread(&temp, sizeof(Zapis), 1, f);
		lista[i] = temp;
	}

	printf("Ima %d zapisa, %d blokova (svaki po %d zapisa), te ima %d vodecih zapisa.\n", br_zapisa, br_blokova, vel_bloka, br_blokova);

	for (i = 0; i < br_blokova; i++)
	{
		printf("%d %s %s\n", lista[i].mbr, lista[i].ime, lista[i].prezime);
	}

	return 0;
}