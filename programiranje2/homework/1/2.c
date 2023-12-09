#include <stdio.h>
#include <string.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 2. - Napisati program koji unosi riječi sve dok se neka riječ ne ponovi, ne nužno zaredom, i
	nakon toga ispisuje sve unesene riječi sortirane po duljini riječi, odnosno abecedi ako je
	duljina ista.
*/

void zamijeni(char a[64], char b[64]);

int main()
{
	char rijeci[64][64];
	int kontrola = 0; // sluzi da zaustavimo do-while petlju kada se nadje ponavljajuca rijec
	int i;						// broj rijeci
	int j, k;

	i = 0;
	do
	{
		if (i >= 64)
		{
			printf("Unijeli ste previse rijeci!\n");
			return 0;
		}

		printf("Unesite rijec: ");
		gets(rijeci[i]);

		for (j = 0; j < i; j++)
		{
			if (strcmp(rijeci[i], rijeci[j]) == 0)
			{
				kontrola = 1;
				break;
			}
		}

		i++;
	} while (kontrola == 0);

	for (j = 0; j < i - 1; j++)
	{
		for (k = j; k < i; k++)
		{
			int razlika_duljina = strlen(rijeci[j]) - strlen(rijeci[k]);
			if (razlika_duljina == 0)
			{
				int razlika_slova = strcmp(rijeci[j], rijeci[k]);
				if (razlika_slova > 0)
				{
					zamijeni(rijeci[j], rijeci[k]);
				}
			}
			else if (razlika_duljina > 0)
			{
				zamijeni(rijeci[j], rijeci[k]);
			}
		}
	}

	printf("Sortirane rijeci: \n");
	for (j = 0; j < i; j++)
	{
		printf("%s\n", rijeci[j]);
	}

	return 0;
}

void zamijeni(char a[64], char b[64])
{
	char temp[64];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}