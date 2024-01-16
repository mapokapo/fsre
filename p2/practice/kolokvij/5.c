/* Napišite program koji učitava string i, ako mu je duljina manja od 20, provjerava je li broj samoglasnika veći u prvoj polovini stringa, te rezultat ispisuje na ekran. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int jeste_samoglasnik(char c)
{
	switch (tolower(c))
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return 1;
	default:
		return 0;
	}
}

int main()
{
	char string[128];
	int i, brs1 = 0, brs2 = 0;

	printf("Unesite string: ");
	fflush(stdin);
	gets(string);

	if (strlen(string) < 20)
	{
		for (i = 0; i < (strlen(string) / 2); i++)
		{
			if (jeste_samoglasnik(string[i]))
			{
				brs1++;
			}
		}
		for (i = (strlen(string) / 2); i < strlen(string); i++)
		{
			if (jeste_samoglasnik(string[i]))
			{
				brs2++;
			}
		}

		if (brs1 > brs2)
		{
			printf("Broj samoglasnika u prvoj polovici stringa je veci.\n");
		}
		else if (brs2 > brs1)
		{
			printf("Broj samoglasnika u drugoj polovici stringa je veci.\n");
		}
		else
		{
			printf("Broj samoglasnika u obe polovice stringa je isti.\n");
		}
	}
	else
	{
		printf("String ima vise od 20 slova.\n");
	}

	return 0;
}