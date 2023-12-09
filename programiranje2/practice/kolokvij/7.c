/* Napisite program u kojem inicijalizirate niz karaktera ciji zbroj ASCII vrijednosti mora biti veci od 5. Duljina stringa ne smije biti veca od 10. U datoteku upisite taj niz i ispisite sadrzaj na ekran. */

#include <stdio.h>
#include <string.h>

int zbroj_ascii(char string[])
{
	int i, br = 0;

	for (i = 0; i < strlen(string); i++)
	{
		br += string[i];
	}

	return br;
}

int main()
{
	char string[128];

	while (1)
	{
		printf("Unesite string: ");
		fflush(stdin);
		gets(string);
		if (strlen(string) < 10 && zbroj_ascii(string) > 5)
		{
			break;
		}
	}

	printf("String je: %s\n", string);
}