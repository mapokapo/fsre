#include <stdio.h>

/*
	Leo Petrovic - 2174/RR

	Zadatak 5. - Napisati program koji unosi 20 znakova i rekurzivnom funkcijom jesu_li_velika_slova()
	provjerava jesu li svi unesenih znakovi velika slova engleskog alfabeta. Rezultat se ispisuje
	u glavnom programu.
*/

int jesu_li_velika_slova(char znakovi[20], int i)
{
	if (i < 0)
	{
		return 1;
	}

	if (!(znakovi[i] >= 'A' && znakovi[i] <= 'Z'))
	{
		return 0;
	}

	return jesu_li_velika_slova(znakovi, i - 1);
}

int main()
{
	char znakovi[20];
	int i;

	for (i = 0; i < 20; i++)
	{
		printf("Unesite znak: ");
		scanf(" %c", &znakovi[i]);
	}

	if (jesu_li_velika_slova(znakovi, 19))
	{
		printf("Svi uneseni znakovi su velika slova.\n");
	}
	else
	{
		printf("Neki od unesenih znakova nisu velika slova.\n");
	}

	return 0;
}