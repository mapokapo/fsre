#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOK 60

struct zapis
{
	int pbr;
	char mjesto[50 + 1];
	char opcina[50 + 1];
};

int main()
{
	/*FILE *f = fopen("mjesta.dat", "rb");
	FILE *fidx = fopen("mjesta.idx", "wb");
	int *index, i;

	fseek(f, 0, SEEK_END);
	int broj_zapisa = (ftell(f) / sizeof(struct zapis));
	int broj_blokova = ceil((float)broj_zapisa / BLOK);
	printf("Broj zapisa %d", broj_zapisa);
	printf("\nBroj blokova %d\n", broj_blokova);

	index = malloc(sizeof(int) * broj_blokova);
	for (i = 0; i < broj_blokova; i++)
	{
		fseek(f, i * BLOK * sizeof(struct zapis), SEEK_SET);
		index[i] = ftell(f);
	}

	fwrite(index, sizeof(int), i, fidx);

	fclose(f);
	fclose(fidx);*/

	FILE *f = fopen("mjesta.idx", "rb");
	FILE *fd = fopen("mjesta.dat", "rb");
	struct zapis pom;
	int adr;
	while (fread(&adr, sizeof(int), 1, f))
	{
		fseek(fd, adr, SEEK_SET);
		fread(&pom, sizeof(struct zapis), 1, fd);
		printf("\n%d %d %s", adr, pom.pbr, pom.mjesto);
	}

	return 0;
}