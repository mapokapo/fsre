#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 1. - Napisati program koji unosi tekst i formira novi string u kojem se slova engleskog
	alfabeta unesenog teksta pojavljuju u obrnutom rasporedu i da su mala slova
	zamijenjena velikim i obrnuto. Npr. za uneseni tekst: "Danas je petak, 24. 03. 2023.
	godine." Formira se string: "ENIDOGKATEPEJSANAd".
*/

int main()
{
	char tekst[128];
	char novi[128];
	int i, j;

	printf("Unesite tekst: ");
	gets(tekst);

	j = 0;
	for (i = strlen(tekst) - 1; i >= 0; i--)
	{
		char s = tekst[i];
		if (isalpha(s))
		{
			if (s >= 'a' && s <= 'z')
				novi[j] = toupper(s);
			else
				novi[j] = tolower(s);
			j++;
		}
	}
	novi[j] = '\0';

	printf("Novi string je: %s\n", novi);

	return 0;
}