#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int mbr;
	char ime[21];
	char prezime[21];
} Zapis;

int main()
{
	FILE *a, *b;
	char buffer[256];

	Zapis *zapisi = NULL;
	Zapis temp;
	int broj_zapisa;

	a = fopen("djelatnici.txt", "r");
	if (a == NULL)
	{
		printf("Datoteka 'djelatnici.txt' nije pronadjena!\n");
		return 1;
	}

	broj_zapisa = 0;
	while (fgets(buffer, 256, a))
	{
		sscanf(buffer, "%d %s %s", &temp.mbr, temp.ime, temp.prezime);

		zapisi = realloc(zapisi, sizeof(Zapis) * (broj_zapisa + 1));
		zapisi[broj_zapisa++] = temp;
	}

	fclose(a);

	b = fopen("djelatnici.dat", "wb");
	if (b == NULL)
	{
		printf("Datoteka 'djelatnici.dat' nije pronadjena!\n");
		return 1;
	}

	fwrite(zapisi, sizeof(Zapis), broj_zapisa, b);

	fclose(b);

	return 0;
}