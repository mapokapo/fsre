#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Leo Petrovic, 2174/RR

	Zadatak 1. - Napisati program koji unosi stringove sve dok se ne unese kraj i, nakon svakog unosa
	popunjava niz struktura za zapis podataka o znakovima engleskog alfabeta: znak (char) i
	broj njegovih ponavljanja u unesenim stringovima (int), pri čemu se zanemaruje razlika
	velikih i malih slova, a znakovi koji nisu slova se ne uzimaju u obzir, sortira znakove
	stringa po broju ponavljanja te formira i ispisuje novi string sastavljen od tako sortiranih
	slova i brojeva njihovih ponavljanja, razdvojenih zarezom, dok se između dva slova
	ispisuje znak - (npr: "a,6-e,5-n,4-…" ).
*/

struct Znak
{
	char znak;
	int broj_ponavljanja;
};

struct Znak preradi_string(char znak, struct Znak znakovi[], int broj_znakova)
{
	struct Znak preradjeni_znak;
	int i, brojac = 1;

	for (i = 0; i < broj_znakova; i++)
	{
		if (tolower(znakovi[i].znak) == tolower(znak))
		{
			brojac++;
		}
	}

	preradjeni_znak.znak = tolower(znak);
	preradjeni_znak.broj_ponavljanja = brojac;

	return preradjeni_znak;
}

int main()
{
	char string[256], string_mali[256], novi_string[256 * 4];
	struct Znak znakovi[256];
	int i, j, redni_broj_stringa = 0, broj_znakova = 0;

	while (1)
	{
		// Provjera da ne unesemo previse stringova
		if (redni_broj_stringa >= 256)
		{
			printf("Unijeli ste previse stringova!\n");
			return 1;
		}

		// Unosenje stringa
		printf("Unesite string: ");
		gets(string);

		for (i = 0; i < strlen(string); i++)
		{
			// Pretvaranje u mala slova za provjeru
			string_mali[i] = tolower(string[i]);
		}
		string_mali[i] = '\0';

		// Uvjet za zavrsetak petlje
		if (strcmp(string_mali, "kraj") == 0)
		{
			break;
		}

		for (i = 0; i < strlen(string); i++)
		{
			// Preskakanje znakova koji nisu alfabeticni
			if (!isalpha(string[i]))
			{
				continue;
			}

			// Pretvaranje u strukturu Znak
			// niz "znakovi" sadrzi svaki znak od svih stringova po redu ("lijepo", "je", "vrijeme" => [l,i,j,e,p,o,j,e,v,r,i,j,e,m,e])
			znakovi[broj_znakova] = preradi_string(string[i], znakovi, broj_znakova);
			// Potreban nam je posebni brojac za niz "znakovi" jer se neki znakovi mogu preskociti (npr. ako nisu alfabeticni)
			broj_znakova++;
		}

		redni_broj_stringa++;
	};

	// Sortiranje niza
	for (i = 0; i < broj_znakova - 1; i++)
	{
		for (j = i + 1; j < broj_znakova; j++)
		{
			if (znakovi[i].broj_ponavljanja < znakovi[j].broj_ponavljanja)
			{
				struct Znak temp = znakovi[i];
				znakovi[i] = znakovi[j];
				znakovi[j] = temp;
			}
		}
	}

	// Formiranje novog stringa
	j = 0;
	for (i = 0; i < broj_znakova; i++)
	{
		novi_string[j] = znakovi[i].znak;
		novi_string[j + 1] = ',';
		novi_string[j + 2] = znakovi[i].broj_ponavljanja + '0';
		if (i <= broj_znakova - 2)
		{
			novi_string[j + 3] = '-';
			j += 4;
		}
		else
		{
			j += 3;
		}
	}
	novi_string[j] = '\0';

	// Ispis rezultata
	printf("Novi string: %s\n", novi_string);

	return 0;
}