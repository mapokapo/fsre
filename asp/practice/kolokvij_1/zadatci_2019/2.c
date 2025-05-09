#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *brojRijeciURecenici(char *recenica, char delimiter, int *n)
{
	char *kopija;
	int *brojZnakovaPoRijeci = NULL;
	char delim[2];
	char *token;
	int i;

	kopija = malloc(sizeof(char) * (strlen(recenica) + 1));
	strcpy(kopija, recenica);

	delim[0] = delimiter;
	delim[1] = '\0';

	token = strtok(kopija, delim);

	i = 0;
	while (token != NULL)
	{

		brojZnakovaPoRijeci = realloc(brojZnakovaPoRijeci, sizeof(int) * (i + 1));
		brojZnakovaPoRijeci[i] = strlen(token);

		token = strtok(NULL, delim);

		i++;
	}

	*n = i;

	return brojZnakovaPoRijeci;
}

int main()
{
	int *polje;
	int i, n;

	polje = brojRijeciURecenici("Ovo je recenica", ' ', &n);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", polje[i]);
	}

	return 0;
}