#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BROJ_RECENICA 5 // proizvoljan broj recenica - 5

/*
	Leo Petrovic 2174/RR

	Zadatak 5. - Napisati program koji unosi niz rečenica i ispisuje samo one od njih koje su palindromi
	(tekst koji se čita isto od naprijed i od nazad, ne uzimajući u obzir razliku velikih i malih
	slova i zanemarujući razmake i interpunkciju). Primjeri palindroma su "Ana voli
	Milovana." i "Udovica baci vodu."
*/

int main()
{
	char recenice[BROJ_RECENICA][256];
	char nove_recenice[BROJ_RECENICA][256];
	int i, j;

	for (i = 0; i < BROJ_RECENICA; i++)
	{
		printf("Unesi recenicu: ");
		gets(recenice[i]);
	}

	// Pretvaramo originalne recenice u nove recenice gdje su sva slova mala i gdje su razmaci i interpunkcija zanemareni.
	for (i = 0; i < BROJ_RECENICA; i++)
	{
		int k = 0;
		for (j = 0; j < strlen(recenice[i]); j++)
		{
			if (isalpha(recenice[i][j]))
			{
				nove_recenice[i][k] = tolower(recenice[i][j]);
				k++;
			}
		}
		nove_recenice[i][j] = '\0';
	}

	for (i = 0; i < BROJ_RECENICA; i++)
	{
		int kontrola = 1;
		for (j = 0; j < strlen(nove_recenice[i]); j++)
		{
			// Ako prvo slovo nije jednako zadnjem, ako drugo slovo nije jednako predzadnjem, itd.
			if (nove_recenice[i][j] != nove_recenice[i][strlen(nove_recenice[i]) - j - 1])
			{
				kontrola = 0;
				break;
			}
		}
		if (kontrola)
		{
			printf("Recenica '%s' je palindrom.\n", recenice[i]);
		}
		else
		{
			printf("Recenica '%s' nije palindrom.\n", recenice[i]);
		}
	}

	return 0;
}