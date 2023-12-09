/*
	Leo Petrovic, 2174/RR

	Zadatak 5. - Napisati program koji definira strukturu za zapis podataka o automobilima: proizvođač
	(string), model (string), snaga motora (int) i cijena (float). Dinamički se alocira memorija
	za niz od 10 automobila i unose se podaci o automobilima, te se sortiraju po
	proizvođaču, odnosno modelu (ako je proizvođač isti). Unosi se dodatni realan broj i
	ispisuju podaci o automobilima čija je cijena manja od dodatnog broja. Koristiti
	isključivo sintaksu pokazivača.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DULJINA_NIZA 10

struct Automobil
{
	char *proizvodjac;
	char *model;
	int snaga;
	float cijena;
};

int main()
{
	struct Automobil *automobili = malloc(sizeof(struct Automobil) * DULJINA_NIZA);
	char proizvodjac[256], model[256], snaga[256], cijena[256];
	float broj;
	int i, j;

	for (i = 0; i < DULJINA_NIZA; i++)
	{
		printf("Unesite proizvodjaca %d. auta: ", i + 1);
		fgets(proizvodjac, 256, stdin);
		(automobili + i)->proizvodjac = (char *)malloc(sizeof(char) * strlen(proizvodjac));
		sscanf(proizvodjac, "%[^\n]", (automobili + i)->proizvodjac);

		printf("Unesite model %d. auta: ", i + 1);
		fgets(model, 256, stdin);
		(automobili + i)->model = (char *)malloc(sizeof(char) * strlen(model));
		sscanf(model, "%[^\n]", (automobili + i)->model);

		printf("Unesite snagu %d. auta: ", i + 1);
		fgets(snaga, 256, stdin);
		sscanf(snaga, "%d", &(automobili + i)->snaga);

		printf("Unesite cijenu %d. auta: ", i + 1);
		fgets(cijena, 256, stdin);
		sscanf(cijena, "%f", &(automobili + i)->cijena);
	}

	for (i = 0; i < DULJINA_NIZA - 1; i++)
	{
		for (j = i + 1; j < DULJINA_NIZA; j++)
		{
			if (
					strcmp((automobili + i)->proizvodjac, (automobili + j)->proizvodjac) == 0 &&
							strcmp((automobili + i)->model, (automobili + j)->model) > 0 ||
					strcmp((automobili + i)->proizvodjac, (automobili + j)->proizvodjac) > 0)
			{
				struct Automobil temp = *(automobili + i);
				*(automobili + i) = *(automobili + j);
				*(automobili + j) = temp;
			}
		}
	}

	printf("Unesite realan broj: ");
	scanf("%f", &broj);

	printf("Podaci o autima cija je cijena manja od unesenog broja:\n");
	for (i = 0; i < DULJINA_NIZA; i++)
	{
		if ((automobili + i)->cijena < broj)
		{
			printf("%s %s (%d kWh) - %.2f\n", (automobili + i)->proizvodjac, (automobili + i)->model, (automobili + i)->snaga, (automobili + i)->cijena);
		}
	}

	return 0;
}