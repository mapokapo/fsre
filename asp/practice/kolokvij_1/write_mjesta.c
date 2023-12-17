#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOK 60
typedef struct
{
	int pbr;
	char mjesto[50 + 1];
	char opcina[50 + 1];
} zapis;

int main()
{
	FILE *f, *fb;
	zapis pom;
	int br;
	f = fopen("mjesta.txt", "r");
	fb = fopen("mjesta.dat", "wb+");
	// Početak datoteke
	fseek(f, 0, SEEK_SET);
	fseek(fb, 0, SEEK_SET);
	// Prebaci podatke
	br = 0;
	while (fscanf(f, "%[^,],%d,%[^\n] ", pom.mjesto, &pom.pbr, pom.opcina) != EOF)
	{
		fwrite(&pom, sizeof(zapis), 1, fb);
		br++;
	}
	int F = br;
	fclose(f);
	fclose(fb);
	printf("Ukupno: %d zapisa", br);

	printf("Zapisa: %d", F);
	printf("\nBlokova: %d", (int)ceil((float)F / BLOK));
	printf("\nBlok: %d", BLOK);
}