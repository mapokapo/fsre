#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 4. - Napisati program koji unosi 10 stringova i još dva dodatna stringa te ispisuje one
	unesene stringove koji po abecedi (ne vodeći računa o razlici velikih i malih slova) dolaze
	između dva dodatna stringa.
*/

int main()
{
	char stringovi[10][64];
	char dodatni[2][64];
	char dodatni1_mali[64], dodatni2_mali[64];
	int i, j;

	printf("Unesite 10 stringova.\n");
	for (i = 0; i < 10; i++)
	{
		printf("Unesite string: ");
		gets(stringovi[i]);
	}

	printf("Unesite 2 dodatna stringa.\n");
	for (i = 0; i < 2; i++)
	{
		printf("Unesite string: ");
		gets(dodatni[i]);
	}

	for (j = 0; j < strlen(dodatni[0]); j++)
	{
		dodatni1_mali[j] = tolower(dodatni[0][j]);
	}
	dodatni1_mali[j] = '\0';
	for (j = 0; j < strlen(dodatni[1]); j++)
	{
		dodatni2_mali[j] = tolower(dodatni[1][j]);
	}
	dodatni2_mali[j] = '\0';

	printf("Stringovi koji se po ASCII kodovima (bez obzira na velika/mala slova) nalaze izmedju stringova '%s' i '%s' su: \n", dodatni[0], dodatni[1]);
	for (i = 0; i < 10; i++)
	{
		// Stvaramo novi string koji je jednak originalnom stringu ali sa malim slovima
		char string_mali[64];
		for (j = 0; j < strlen(stringovi[i]); j++)
		{
			string_mali[j] = tolower(stringovi[i][j]);
		}
		string_mali[j] = '\0';
		// ako se string nalazi izmedju dodatni[0] i dodatni[1] (bez obzira na velika/mala slova) onda ga ispisujemo
		if (strcmp(string_mali, dodatni1_mali) > 0 && strcmp(string_mali, dodatni2_mali) < 0)
		{
			printf("%s\n", stringovi[i]);
		}
	}

	return 0;
}