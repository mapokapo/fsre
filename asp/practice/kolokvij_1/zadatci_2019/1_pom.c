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

int main()
{
	FILE *a, *b;
	char buffer[256];

	student *studenti = NULL;
	student temp, prazan_student;
	int broj_studenata, i;

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
		sscanf(buffer, "%d %s %s %d", &temp.sifra, temp.ime, temp.prezime, &temp.ocjena);
		printf("[%d] %d %s %s %d\n", broj_studenata, temp.sifra, temp.ime, temp.prezime, temp.ocjena);

		studenti = realloc(studenti, sizeof(student) * (broj_studenata + 1));
		studenti[broj_studenata] = temp;

		broj_studenata++;
	}

	fclose(a);

	b = fopen("studenti.dat", "wb");
	if (b == NULL)
	{
		printf("Datoteka 'studenti.dat' nije pronadjena!\n");
		return 1;
	}

	prazan_student.sifra = 0;
	prazan_student.ocjena = 0;
	for (i = 0; i < 999; i++)
	{
		fseek(b, i * sizeof(student), SEEK_SET);
		fwrite(&prazan_student, sizeof(student), 1, b);
	}

	for (i = 0; i < broj_studenata; i++)
	{
		fseek(b, studenti[i].sifra * sizeof(student), SEEK_SET);
		fwrite(&studenti[i], sizeof(studenti), 1, b);
	}

	fclose(b);

	return 0;
}