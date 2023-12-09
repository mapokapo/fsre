#include <stdio.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 4. -  Napisati program koji definira strukturu za zapis podataka o sportovima: naziv sporta,
	broj igrača u terenu, trajanje utakmice. Program inicijalizira podatke za 10 sportova i
	ispisuje ih sortirane po trajanju utakmice (silazno), odnosno po broju igrača u terenu
	(uzlazno) ako je trajanje utakmice isto.
*/

struct sport
{
	char naziv[32];
	int broj_igraca;
	int trajanje_utakmice;
};

int main()
{
	int i, j;
	struct sport sportovi[10] = {
			{
					"Nogomet",
					22,
					90,
			},
			{
					"Kosarka",
					10,
					48,
			},
			{
					"Tenis",
					2,
					90,
			},
			{
					"Vaterpolo",
					14,
					32,
			},
			{
					"Sport 1",
					20,
					90,
			},
			{
					"Sport 2",
					5,
					50,
			},
			{
					"Sport 3",
					10,
					32,
			},
			{
					"Sport 4",
					15,
					100,
			},
			{
					"Sport 5",
					2,
					48,
			},
			{
					"Sport 7",
					4,
					32,
			}};

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if ((sportovi[i].trajanje_utakmice == sportovi[j].trajanje_utakmice && sportovi[i].broj_igraca > sportovi[j].broj_igraca) || sportovi[i].trajanje_utakmice < sportovi[j].trajanje_utakmice)
			{
				struct sport temp = sportovi[i];
				sportovi[i] = sportovi[j];
				sportovi[j] = temp;
			}
		}
	}

	printf("Sortirani sportovi:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d. %s:\n", i + 1, sportovi[i].naziv);
		printf(" - broj igraca na terenu: %d\n", sportovi[i].broj_igraca);
		printf(" - trajajne utakmice: %d\n", sportovi[i].trajanje_utakmice);
	}

	return 0;
}
