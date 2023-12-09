#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 3. - Napisati program koji definira strukturu za zapis podataka o rijecima rečenice koju unosi
	korisnik: redni broj riječi u rečenici (int), tekst riječi (string), broj samoglasnika u riječi
	(int) i slovo koje se najviše puta ponavlja (char). Ispisuju se podaci o svim riječima
	sortirani po broju samoglasnika silazno.
*/

struct rijec
{
	int redni_broj;
	char tekst[256];
	int broj_samoglasnika;
	char najcesce_slovo;
};

int prebroji_samoglasnike(char rijec[256])
{
	int brojac = 0, i;
	for (i = 0; i < strlen(rijec); i++)
	{
		if (rijec[i] == 'a' || rijec[i] == 'e' || rijec[i] == 'i' || rijec[i] == 'o' || rijec[i] == 'u' || rijec[i] == 'A' || rijec[i] == 'E' || rijec[i] == 'I' || rijec[i] == 'O' || rijec[i] == 'U')
		{
			brojac++;
		}
	}

	return brojac;
}

char pronadji_najcesce_slovo(char rijec[256])
{
	int i, j;
	char najcesce = rijec[0];
	int broj_ponavljanja_najcesceg = 1;

	for (i = 0; i < strlen(rijec); i++)
	{
		int broj_ponavljanja = 1;
		for (j = 0; j < strlen(rijec); j++)
		{
			// ne pravimo razliku izmedju velikih i malih slova
			if (tolower(rijec[i]) == tolower(rijec[j]))
			{
				broj_ponavljanja++;
			}
		}
		if (broj_ponavljanja > broj_ponavljanja_najcesceg)
		{
			najcesce = tolower(rijec[i]);
			broj_ponavljanja_najcesceg = broj_ponavljanja;
		}
	}

	return najcesce;
}

struct rijec preradi_rijec(char rijec[256], int redni_broj)
{
	struct rijec preradjena_rijec =
			{
					redni_broj,
					"",
					prebroji_samoglasnike(rijec),
					pronadji_najcesce_slovo(rijec),
			};

	strcpy(preradjena_rijec.tekst, rijec);

	return preradjena_rijec;
}

int main()
{
	char recenica[256];
	char rijec[256];
	struct rijec rijeci[256];
	int i, j = 0, broj_rijeci = 0;

	printf("Unesite recenicu: ");
	gets(recenica);

	for (i = 0; i < strlen(recenica); i++)
	{
		// Ako smo zavrsili sa jednom rjecju
		if (recenica[i] == ' ')
		{
			rijec[j] = '\0';
			rijeci[broj_rijeci] = preradi_rijec(rijec, broj_rijeci + 1);
			broj_rijeci++;
			j = 0;
		}
		// Ako smo na zadnjem slovu recenice
		else if (i >= strlen(recenica) - 1)
		{
			rijec[j] = recenica[i];
			rijec[j + 1] = '\0';
			rijeci[broj_rijeci] = preradi_rijec(rijec, broj_rijeci + 1);
			broj_rijeci++;
			j = 0;
		}
		else
		{
			rijec[j] = recenica[i];
			j++;
		}
	}

	for (i = 0; i < broj_rijeci - 1; i++)
	{
		for (j = i + 1; j < broj_rijeci; j++)
		{
			if (rijeci[i].broj_samoglasnika < rijeci[j].broj_samoglasnika)
			{
				struct rijec temp = rijeci[i];
				rijeci[i] = rijeci[j];
				rijeci[j] = temp;
			}
		}
	}

	printf("Informacije o rijecima: \n");
	for (i = 0; i < broj_rijeci; i++)
	{
		printf("%d. \"%s\"\n", rijeci[i].redni_broj, rijeci[i].tekst);
		printf(" - broj samoglasnika: %d\n", rijeci[i].broj_samoglasnika);
		printf(" - najcesce slovo: %c\n", rijeci[i].najcesce_slovo);
	}

	return 0;
}