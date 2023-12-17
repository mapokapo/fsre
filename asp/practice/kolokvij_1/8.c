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
	int trazeni_mbr = 789;

	FILE *f;

	struct zapis *studenti = NULL;
	struct zapis trazeni_student;
	int broj_studenata, i, j;

	f = fopen("studenti.dat", "rb+");
	if (f == NULL)
	{
		printf("Datoteka 'studenti.dat' nije pronadjena!\n");
		return 1;
	}

	fseek(f, 0, SEEK_END);
	broj_studenata = ftell(f) / sizeof(struct zapis);
	rewind(f);

	studenti = malloc(sizeof(struct zapis) * broj_studenata);
	fread(studenti, sizeof(struct zapis), broj_studenata, f);

	for (i = 0; i < broj_studenata; i++)
	{
		if (studenti[i].mbr == trazeni_mbr)
		{
			trazeni_student = studenti[i];
			break;
		}
	}

	printf("Trazeni student je %s (MBR: %d), spol %s, index: %d.\n", trazeni_student.ime, trazeni_student.mbr, trazeni_student.spol, i);

	printf("Brisanje studenta i spremanje...\n");

	trazeni_student.mbr = 0;
	studenti[i] = trazeni_student;
	printf("Trazeni student je %s (MBR: %d), spol %s, index: %d.\n", studenti[i].ime, studenti[i].mbr, studenti[i].spol, i);

	fseek(f, 0, SEEK_SET);
	fwrite(studenti, sizeof(struct zapis), broj_studenata, f);

	fclose(f);

	return 0;
}