#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int sifra;
	char ime[20 + 1];
	char prezime[30 + 1];
	int ocjena;
} student;

student *NisuPolozili(char *nazivDatoteke, int *out)
{
	FILE *f;
	student *studenti = NULL, temp;
	int broj_studenata;

	f = fopen(nazivDatoteke, "rb");
	if (f == NULL)
	{
		printf("Datoteka '%s' nije pronadjena!\n", nazivDatoteke);
		return NULL;
	}

	broj_studenata = 0;
	while (fread(&temp, sizeof(student), 1, f) == 1)
	{
		if (temp.sifra != 0 && temp.ocjena < 0)
		{
			studenti = realloc(studenti, sizeof(student) * (broj_studenata + 1));
			studenti[broj_studenata] = temp;

			broj_studenata++;
		}
	};

	*out = broj_studenata;

	return studenti;
}

int main()
{
	student *studenti;
	int broj_studenata, i;

	studenti = NisuPolozili("studenti.dat", &broj_studenata);
	printf("%d\n", broj_studenata);

	for (i = 0; i < broj_studenata; i++)
	{
		printf("[%d] %s %s %d\n", studenti[i].sifra, studenti[i].ime, studenti[i].prezime, studenti[i].ocjena);
	}

	return 0;
}