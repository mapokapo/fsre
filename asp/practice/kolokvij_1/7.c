#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct zapis
{
	int mbr;
	char ime[40 + 1];
	char spol[1 + 1];
};

int main()
{
	FILE *a, *b;
	char buffer[256];

	int mbr;
	char ime[40 + 1], spol[1 + 1];

	struct zapis *studenti = NULL;
	struct zapis temp;
	int broj_studenata, i, j;

	a = fopen("studenti.txt", "r");
	if (a == NULL)
	{
		printf("Datoteka 'studenti.txt' nije pronadjena!\n");
		return 1;
	}

	broj_studenata = 0;
	while (!feof(a))
	{
		fgets(buffer, 256, a);
		sscanf(buffer, "%d %s %s", &mbr, ime, spol);

		studenti = realloc(studenti, sizeof(struct zapis) * (broj_studenata + 1));
		studenti[broj_studenata].mbr = mbr;
		strcpy(studenti[broj_studenata].ime, ime);
		strcpy(studenti[broj_studenata].spol, spol);

		broj_studenata++;
	}

	fclose(a);

	for (i = 0; i < broj_studenata - 1; i++)
	{
		for (j = i + 1; j < broj_studenata; j++)
		{
			if (studenti[i].mbr > studenti[j].mbr)
			{
				temp = studenti[i];
				studenti[i] = studenti[j];
				studenti[j] = temp;
			}
		}
	}

	b = fopen("studenti.dat", "wb");
	if (b == NULL)
	{
		printf("Datoteka 'studenti.dat' nije pronadjena!\n");
		return 1;
	}

	fwrite(studenti, sizeof(struct zapis), broj_studenata, b);

	fclose(b);

	return 0;
}