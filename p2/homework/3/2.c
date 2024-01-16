#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Leo Petrovic, 2174/RR

	Zadatak 2. - Napisati program koji unosi string, rastavlja ga u niz struktura za zapis podataka o
	znakovima u stringu: znak (char) i broj njegovih ponavljanja u stringu (int) na način da su
	sva ponavljanja istog znaka u stringu predstavljena jednim elementom niza, sortira
	znakove stringa po broju pojavljivanja (silazno) te formira i ispisuje novi string sastavljen
	od tako sortiranih slova i broja njihovog ponavljanja (navedenog u zagradi). Sve radnje se
	obavljaju u zasebnim funkcijama, a ispis rezultata u glavnom programu.
*/

struct Znak
{
	char znak;
	int broj_ponavljanja;
};

void unos_stringa(char string[])
{
	printf("Unesite string: ");
	gets(string);
}

int formiraj_niz_znakova(char string[], struct Znak znakovi[])
{
	int i, j, broj_znakova = 0;

	for (i = 0; i < strlen(string); i++)
	{
		// Trazimo indeks gdje se trenutno slovo prvi put pojavljuje u stringu (j je indeks prvog pojavljivanja)
		for (j = 0; j < broj_znakova; j++)
		{
			if (tolower(string[i]) == tolower(znakovi[j].znak))
			{
				znakovi[j].broj_ponavljanja++;
				break;
			}
		}

		// Ako je j jednak broju znakova, znaci da smo prosli kroz cijeli niz i da trenutno slovo nije nadjeno
		// U tom slucaju znamo da je to novo slovo, te ga dodajemo u niz znakova i povecavamo broj ponavljanja za 1
		if (j == broj_znakova)
		{
			znakovi[broj_znakova].znak = tolower(string[i]);
			znakovi[broj_znakova].broj_ponavljanja = 1;
			broj_znakova++;
		}
	}

	return broj_znakova;
}

void sortiraj_znakove(struct Znak znakovi[], int broj_znakova)
{
	int i, j;

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
}

void formiraj_novi_string(struct Znak znakovi[], int broj_znakova, char novi_string[])
{
	int i, j = 0;

	for (i = 0; i < broj_znakova; i++)
	{
		novi_string[j] = znakovi[i].znak;
		novi_string[j + 1] = '(';
		novi_string[j + 2] = znakovi[i].broj_ponavljanja + '0';
		novi_string[j + 3] = ')';
		if (i <= broj_znakova - 2)
		{
			novi_string[j + 4] = ',';
			novi_string[j + 5] = ' ';
			j += 6;
		}
		else
		{
			j += 4;
		}
	}
	novi_string[j] = '\0';
}

int main()
{
	struct Znak znakovi[256];
	char string[256], novi_string[256];
	int broj_znakova;

	unos_stringa(string);
	broj_znakova = formiraj_niz_znakova(string, znakovi);
	sortiraj_znakove(znakovi, broj_znakova);
	formiraj_novi_string(znakovi, broj_znakova, novi_string);

	printf("Novi string: %s\n", novi_string);

	return 0;
}