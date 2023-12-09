#include <stdio.h>

/*
	Leo Petrovic - 2174/RR

	Zadatak 2. - Napisati program koji unosi cijele brojeve sve dok se ne unese prost broj, u funkciji
	najveci() pronalazi najveći uneseni broj, a zatim u funkciji svi_prosti() ispisuje sve proste
	prirodne brojeve manje od najvećeg unesenog broja.
*/

int prost(int broj)
{
	if (broj == 0 || broj == 1)
	{
		return 0;
	}
	int i;
	for (i = 2; i <= broj / 2; i++)
	{
		if (broj % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int najveci(int brojevi[], int broj_brojeva)
{
	int max = brojevi[0];
	int i;

	for (i = 0; i < broj_brojeva; i++)
	{
		if (brojevi[i] > max)
		{
			max = brojevi[i];
		}
	}

	return max;
}

void svi_prosti(int max)
{
	int i;

	for (i = 0; i < max; i++)
	{
		if (prost(i))
		{
			printf("%d je prost.\n", i);
		}
	}
}

int main()
{
	int brojevi[128];
	int i = 0;

	do
	{
		if (i >= 128)
		{
			printf("Unijeli ste previse brojeva!\n");
			return 0;
		}

		printf("Unesite broj: ");
		scanf("%d", &brojevi[i]);

		i++;
	} while (i < 1 || !prost(brojevi[i - 1]));

	int max = najveci(brojevi, i);
	svi_prosti(max);

	return 0;
}