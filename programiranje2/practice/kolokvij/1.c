/* Program učitava string, broji koliko se puta u njemu ponavlja slog 'moj' i broj ponavljanja ispisuje na ekran. */

#include <stdio.h>
#include <string.h>

int main()
{
	char string[128];
	int i, br = 0;

	printf("Unesite string: ");
	fflush(stdin);
	gets(string);

	for (i = 0; i < strlen(string); i++)
	{
		if (string[i] == 'm' && string[i + 1] == 'o' && string[i + 2] == 'j')
		{
			br++;
		}
	}

	printf("Slog 'moj' se ponavlja %d puta u stringu.\n", br);

	return 0;
}