/*
	Leo Petrovic, 2174/RR

	Zadatak 4. - Napisati program koji dinamički alocira memoriju za string koji se formira spajanjem
	unesenih stringova na način da se u obzir uzimaju samo velika slova engleskog alfabeta iz
	unesenih stringova. Memorija se realocira prije dodavanja svakog znaka u formirani
	string. Unos prestaje u trenutku kada broj samoglasnika u formiranom stringu bude veći
	od 10. Nakon toga string se ispisuje. Koristiti isključivo sintaksu pokazivača.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *samo_velika_slova(char *string)
{
	char *novi_string = NULL;
	int i, br = 0;

	for (i = 0; i < strlen(string); i++)
	{
		if (isupper(*(string + i)))
		{
			novi_string = realloc(novi_string, sizeof(char) * (br + 1));
			*(novi_string + br) = *(string + i);
			br++;
		}
	}
	novi_string = realloc(novi_string, sizeof(char) * (br + 1));
	*(novi_string + br) = '\0';

	return novi_string;
}

int broj_samoglasnika(char *string)
{
	int i, br = 0;

	for (i = 0; i < strlen(string); i++)
	{
		switch (tolower(*(string + i)))
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			br++;
			break;
		}
	}

	return br;
}

int main()
{
	char *formirani_string = NULL, buffer[255];
	int i, br = 0;

	while (1)
	{
		printf("Unesite string: ");
		fflush(stdin);
		gets(buffer);

		strcpy(buffer, samo_velika_slova(buffer));

		if (strlen(buffer) > 0)
		{
			formirani_string = realloc(formirani_string, sizeof(char) * strlen(buffer));
			strcat(formirani_string, buffer);

			if (broj_samoglasnika(formirani_string) > 10)
			{
				break;
			}
		}
	}

	printf("Novi string je: %s\n", formirani_string);

	return 0;
}