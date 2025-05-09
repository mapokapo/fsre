/*
	Leo Petrovic, 2174/RR

	Zadatak 3. -  Napisati program koji dinamički alocira memoriju za niz realnih brojeva koji se unose sve
	dok neki od unesenih brojeva ne bude identičan prvom unesenom broju. Memorija se
	realocira prije svakog unosa broja tako da se koristi optimalno. Brojevi se ispisuju,
	sortirani silazno po veličini decimalnog dijela. Koristiti isključivo sintaksu pokazivača.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float *niz = NULL;
	int i, j, br = 0;

	while (1)
	{
		niz = realloc(niz, sizeof(float) * (br + 1));

		printf("Unesite realni broj: ");
		scanf("%f", niz + br);

		if (br != 0 && *(niz + br) == *niz)
		{
			br++;
			break;
		}

		br++;
	}

	for (i = 0; i < br - 1; i++)
	{
		for (j = i + 1; j < br; j++)
		{
			if ((*(niz + i) - (int)*(niz + i)) < (*(niz + j) - (int)*(niz + j)))
			{
				float temp = *(niz + i);
				*(niz + i) = *(niz + j);
				*(niz + j) = temp;
			}
		}
	}

	for (i = 0; i < br; i++)
	{
		printf("%d. broj: %.4f\n", i + 1, *(niz + i));
	}

	return 0;
}