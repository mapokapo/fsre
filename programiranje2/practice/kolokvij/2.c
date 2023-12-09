/* Napišite pogram u kojem se sa tipkovnice unosi string i jedan cijeli broj. Ako je cijeli broj veći od duljine stringa, formatirajte novi string sastavljen od prvog stringa koji se ponavlja toliko puta dok se ne dosegne vrijednost uneseng cijelog broja. Npr. ako je string banana i cijeli broj 20, ispisati će se: bananabananabananaba */

#include <stdio.h>
#include <string.h>

int main()
{
	char string[128], novi_string[128];
	int i, broj;

	printf("Unesite string: ");
	fflush(stdin);
	gets(string);

	printf("Unesite cijeli broj: ");
	scanf("%d", &broj);

	if (broj > strlen(string))
	{
		// novi_string = "banana", treba biti "bananabananabananaba"
		strcpy(novi_string, string);
		// trebamo dodati 2 puta "banana"
		// broj_dodavanja = 20 / 6 - 1 = 2
		int broj_dodavanja = broj / strlen(string) - 1;

		for (i = 0; i < broj_dodavanja; i++)
		{
			strcat(novi_string, string);
		}

		// trebamo jos dodati 2 slova ("ba") na kraju
		// broj_preostalih_slova = 20 % 6 = 2
		int duljina_novog_stringa = strlen(novi_string);
		int broj_preostalih_slova = broj % strlen(string);

		for (i = 0; i < broj_preostalih_slova; i++)
		{
			novi_string[duljina_novog_stringa + i] = string[i];
		}
		if (broj_preostalih_slova > 0)
		{
			novi_string[strlen(novi_string)] = '\0';
		}

		printf("Novi string je: %s\n", novi_string);
	}
	else
	{
		printf("Broj je manji od duljine stringa.\n");
	}

	return 0;
}