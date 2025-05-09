#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOK 60

struct zapis
{
	int pbr;
	char mjesto[50 + 1];
	char opcina[50 + 1];
};

int main()
{
	FILE *f = fopen("mjesta.dat", "rb");
	struct zapis pom;
	int broj_zapisa, velicina;

	// a
	broj_zapisa = 0;
	while (!feof(f))
	{
		if (fread(&pom, sizeof(struct zapis), 1, f) != 0)
			broj_zapisa++;
	}
	velicina = broj_zapisa * sizeof(struct zapis);

	printf("\nVeličina: %d", velicina);
	printf("\nBroj zapisa: %d", broj_zapisa);

	// b
	fseek(f, 0, SEEK_END);
	velicina = ftell(f);
	fseek(f, 0, SEEK_SET);
	broj_zapisa = velicina / sizeof(struct zapis);

	printf("\nVeličina: %d", velicina);
	printf("\nBroj zapisa: %d", broj_zapisa);

	fclose(f);

	return 0;
}