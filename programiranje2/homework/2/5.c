#include <stdio.h>
#include <string.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 5. - Napisati program koji definira strukturu za zapis podataka o studentima: prezime i ime
	(string), studij (string), semestar (int) i prosjek ocjena (float). Program unosi podatke za 5
	studenata s tim da studij može biti jedan od pobrojanih: strojarstvo, računarstvo i
	elektrotehnika. Ispisuju se podaci o studentima, sortirani po studiju i abecedi (ukoliko je
	studij isti) te se nakon svih studenata jednog studija (a prije studenata sljedećeg studija)
	ispisuje broj studenata i najveći prosjek ocjena na tom studiju.
*/

struct student
{
	char prezime_ime[64];
	char studij[64];
	int semestar;
	float prosjek_ocjena;
};

int broj_studenata_na_studiju(struct student studenti[5], char studij[64])
{
	int i, broj_studenata = 0;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(studenti[i].studij, studij) == 0)
		{
			broj_studenata++;
		}
	}

	return broj_studenata;
}

float prosjecna_ocjena_studenata_na_studiju(struct student studenti[5], char studij[64], int broj_studenata_na_studiju)
{
	int i;
	float zbroj_ocjena = 0;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(studenti[i].studij, studij) == 0)
		{
			zbroj_ocjena += studenti[i].prosjek_ocjena;
		}
	}

	return zbroj_ocjena / broj_studenata_na_studiju;
}

int main()
{
	int i = 0, j;
	char prezime_ime[64];
	char studij[64];
	char semestar[64];
	char prosjek_ocjena[64];
	struct student student;
	struct student studenti[5];

	do
	{
		printf("Student %d:\n", i + 1);

		printf(" - prezime i ime studenta: ");
		fgets(prezime_ime, 64, stdin);
		sscanf(prezime_ime, "%[^\n]", student.prezime_ime);

		printf(" - studij studenta: ");
		fgets(studij, 64, stdin);
		sscanf(studij, "%[^\n]", student.studij);
		if (!(strcmp(student.studij, "elektrotehnika") == 0 || strcmp(student.studij, "strojarstvo") == 0 || strcmp(student.studij, "racunarstvo") == 0))
		{
			printf("Nevazeci studij! Pokusajte ponovno\n");
			continue;
		}

		printf(" - semestar studenta: ");
		fgets(semestar, 64, stdin);
		sscanf(semestar, "%d", &student.semestar);

		printf(" - prosjek ocjena studenta: ");
		fgets(prosjek_ocjena, 64, stdin);
		sscanf(prosjek_ocjena, "%f", &student.prosjek_ocjena);

		studenti[i] = student;

		i++;
	} while (i < 5);

	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{

			if ((strcmp(studenti[i].studij, studenti[j].studij) == 0 && strcmp(studenti[i].prezime_ime, studenti[j].prezime_ime) > 0) || strcmp(studenti[i].studij, studenti[j].studij) < 0)
			{
				struct student temp = studenti[i];
				studenti[i] = studenti[j];
				studenti[j] = temp;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		printf("%s (%s, %d. semestar, prosjek ocjena: %.2f)\n", studenti[i].prezime_ime, studenti[i].studij, studenti[i].semestar, studenti[i].prosjek_ocjena);
		if (i == 4 || strcmp(studenti[i].studij, studenti[i + 1].studij) != 0)
		{
			int br = broj_studenata_na_studiju(studenti, studenti[i].studij);
			printf("%s - broj studenata: %d, prosjecna ocjena studenata: %.2f\n\n", studenti[i].studij, br, prosjecna_ocjena_studenata_na_studiju(studenti, studenti[i].studij, br));
		}
	}

	return 0;
}