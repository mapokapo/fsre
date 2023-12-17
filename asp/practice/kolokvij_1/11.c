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

void vodeci(int n)
{
	struct zapis pom;
	FILE *f = fopen("mjesta.dat", "rb");

	fseek(f, (n - 1) * BLOK * sizeof(struct zapis), SEEK_SET);
	fread(&pom, sizeof(struct zapis), 1, f);

	// Ispis
	printf("%d %s %s", pom.pbr, pom.mjesto, pom.opcina);
	fclose(f);
}

int main()
{
	vodeci(60);

	return 0;
}