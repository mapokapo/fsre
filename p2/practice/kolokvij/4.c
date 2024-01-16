/* Definirajte funkciju int duljina_stringa(char *str1) koja ommogućava računanje duljine stringa str1(ne koristiti funkciju strlen!) U glavnom programu inicijalizirati string, te pozvati funkciju i ispisati mu duljinu. */

#include <stdio.h>

int duljina_stringa(char string[])
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}

	return i;
}

int main()
{
	char string[128];

	printf("Unesite string: ");
	fflush(stdin);
	gets(string);

	printf("Duljina stringa: %d\n", duljina_stringa(string));

	return 0;
}