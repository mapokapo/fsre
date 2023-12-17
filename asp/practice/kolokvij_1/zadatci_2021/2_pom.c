#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char mbr[20 + 1];
	char ime[20 + 1];
	char prezime[20 + 1];
} zapis;

int main()
{
	FILE *a, *b;
	char buffer[256];

	zapis *zapisi = NULL;
	zapis temp;
	int broj_zapisa;

	a = fopen("djelatnici_mbr.txt", "r");
	if (a == NULL)
	{
		printf("Datoteka 'djelatnici_mbr.txt' nije pronadjena!\n");
		return 1;
	}

	broj_zapisa = 0;
	while (!feof(a))
	{
		fgets(buffer, 256, a);
		sscanf(buffer, "%s %s %[^\n]", temp.mbr, temp.ime, temp.prezime);
		printf("[%d] %s %s %s\n", broj_zapisa, temp.mbr, temp.ime, temp.prezime);

		zapisi = realloc(zapisi, sizeof(zapis) * (broj_zapisa + 1));
		strcpy(zapisi[broj_zapisa].mbr, temp.mbr);
		strcpy(zapisi[broj_zapisa].ime, temp.ime);
		strcpy(zapisi[broj_zapisa].prezime, temp.prezime);

		broj_zapisa++;
	}

	fclose(a);

	b = fopen("djelatnici_mbr.dat", "wb");
	if (b == NULL)
	{
		printf("Datoteka 'djelatnici_mbr.dat' nije pronadjena!\n");
		return 1;
	}

	fwrite(zapisi, sizeof(zapis), broj_zapisa, b);

	fclose(b);

	return 0;
}