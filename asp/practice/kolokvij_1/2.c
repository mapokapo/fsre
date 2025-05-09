#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *a, *b;
	char ime_prve_dat[256], ime_druge_dat[256], buffer[256];
	char **redci = NULL;
	int broj_redaka, i;

	printf("Napisite ime prve datoteke: ");
	scanf("%s", ime_prve_dat);

	printf("Napisite ime druge datoteke: ");
	scanf("%s", ime_druge_dat);

	a = fopen(ime_prve_dat, "r");
	if (a == NULL)
	{
		printf("Datoteka '%s' nije pronadjena!\n", ime_prve_dat);
		return 1;
	}

	b = fopen(ime_druge_dat, "w");
	if (b == NULL)
	{
		printf("Datoteka '%s' nije pronadjena!\n", ime_druge_dat);
		return 1;
	}

	broj_redaka = 0;
	while (fgets(buffer, 256, a))
	{
		sscanf(buffer, "%[^\n]", buffer);

		redci = realloc(redci, sizeof(char *) * (broj_redaka + 1));
		redci[broj_redaka] = malloc(sizeof(char) * 256);

		strcpy(redci[broj_redaka], buffer);

		broj_redaka++;
	}

	fclose(a);

	for (i = broj_redaka - 1; i >= 0; i--)
	{
		fputs(redci[i], b);
		fputs("\n", b);
	}

	fclose(b);

	return 0;
}