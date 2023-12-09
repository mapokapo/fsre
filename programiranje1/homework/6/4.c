#include <stdio.h>

/*
	Leo Petrovic - 2174/RR

	Zadatak 4. - Napisati program koji unosi realne brojeve sve dok zadnji uneseni broj ne bude jednak
	nekom od ranije unesenih brojeva. Nakon toga program u funkciji ispis() ispisuje one
	brojeve čiji je cijeli dio 100 ili više puta veći od specijalnog dijela.
*/

int isti_par(float brojevi[], int broj_brojeva, float broj)
{
	int i;

	for (i = 0; i < broj_brojeva; i++)
	{
		if (brojevi[i] == broj)
		{
			return 1;
		}
	}

	return 0;
}

void ispis(float brojevi[], int broj_brojeva)
{
	int i;

	for (i = 0; i < broj_brojeva; i++)
	{
		int cijeli_dio = (int)brojevi[i];
		float decimalni_dio = brojevi[i] - cijeli_dio;

		if (cijeli_dio >= 100 * decimalni_dio)
		{
			printf("Broj %f ima cijeli dio koji je bar 100 puta veci od decimalnog.\n", brojevi[i]);
		}
	}
}

int main()
{
	float brojevi[128];
	int i = 0;

	do
	{
		if (i >= 128)
		{
			printf("Unijeli ste previse brojeva!\n");
			return 0;
		}

		printf("Unesite broj: ");
		scanf("%f", &brojevi[i]);

		i++;
	} while (i < 2 || !isti_par(brojevi, i - 1, brojevi[i - 1]));

	ispis(brojevi, i);

	return 0;
}