#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
	Leo Petrovic, 2174/RR

	Zadatak 5. - Napisati program koji definira strukturu za zapis podataka o rečenicama: tekst rečenice
	(string), broj riječi u rečenici (int), duljina rečenice (int) i najduža riječ (string - ukoliko je
	više riječi iste duljine odabire se ona koja je prva po abecedi). Korisnik unosi rečenice sve
	dok ne unese tekst kraj, a zatim se unesene rečenice sortiraju po broju riječi, odnosno
	po duljini rečenice ako je broj riječi isti te se formira novi string na način da se iz tako
	sortiranih rečenica uzmu najdulje riječi i spoje u novi string u kojem će biti odvojene
	razmacima. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata u glavnom
	programu.
*/

struct Recenica
{
	char tekst[128];
	int broj_rijeci;
	int duljina_recenice;
	char najduza_rijec[128];
};

struct Recenica preradi_recenicu(char recenica[])
{
	struct Recenica nova_recenica;
	int broj_rijeci = 0, duljina_recenice = strlen(recenica), duljina_rijeci = 0, duljina_najduze_rijeci = 0, indeks_najduze_rijeci = 0;
	char najduza_rijec[128];
	int i, j;

	for (i = 0; i <= duljina_recenice; i++)
	{
		if (recenica[i] == ' ' || recenica[i] == '\0')
		{
			broj_rijeci++;

			// Ako su rijeci iste duljine, usporedi ih po abecedi
			if (duljina_rijeci == duljina_najduze_rijeci)
			{
				for (j = 0; j < duljina_rijeci; j++)
				{
					if (tolower(recenica[i - duljina_rijeci + j]) < tolower(recenica[indeks_najduze_rijeci + j]))
					{
						duljina_najduze_rijeci = duljina_rijeci;
						indeks_najduze_rijeci = i - duljina_rijeci;
						break;
					}
					else if (tolower(recenica[i - duljina_rijeci + j]) > tolower(recenica[indeks_najduze_rijeci + j]))
					{
						break;
					}
				}
			}
			else if (duljina_rijeci > duljina_najduze_rijeci)
			{
				duljina_najduze_rijeci = duljina_rijeci;
				indeks_najduze_rijeci = i - duljina_rijeci;
			}

			duljina_rijeci = 0;
		}
		else
		{
			duljina_rijeci++;
		}
	}

	for (i = 0; i < duljina_najduze_rijeci; i++)
	{
		najduza_rijec[i] = recenica[indeks_najduze_rijeci + i];
	}
	najduza_rijec[i] = '\0';

	strcpy(nova_recenica.tekst, recenica);
	strcpy(nova_recenica.najduza_rijec, najduza_rijec);
	nova_recenica.broj_rijeci = broj_rijeci;
	nova_recenica.duljina_recenice = duljina_recenice;

	return nova_recenica;
}

int unos(char recenice[64][128])
{
	char recenica[128], recenica_mali[128];
	int i, broj_recenica = 0;
	while (1)
	{
		// Provjera da ne unesemo previse stringova
		if (broj_recenica >= 64)
		{
			printf("Unijeli ste previse recenica!\n");
			break;
		}

		// Unosenje stringa
		printf("Unesite recenicu: ");
		gets(recenica);

		for (i = 0; i < strlen(recenica); i++)
		{
			// Pretvaranje u mala slova za provjeru
			recenica_mali[i] = tolower(recenica[i]);
		}
		recenica_mali[i] = '\0';

		// Uvjet za zavrsetak petlje
		if (strcmp(recenica_mali, "kraj") == 0)
		{
			break;
		}

		// Kopiranje stringa u niz stringova
		strcpy(recenice[broj_recenica], recenica);

		broj_recenica++;
	}

	return broj_recenica;
}

void preradi_recenice(char unesene_recenice[64][128], struct Recenica recenice[64], int broj_recenica)
{
	int i;
	for (i = 0; i < broj_recenica; i++)
	{
		recenice[i] = preradi_recenicu(unesene_recenice[i]);
	}
}

void sortiraj(struct Recenica recenice[64], int broj_recenica)
{
	int i, j;

	for (i = 0; i < broj_recenica - 1; i++)
	{
		for (j = i + 1; j < broj_recenica; j++)
		{
			if (recenice[i].broj_rijeci < recenice[j].broj_rijeci || (recenice[i].broj_rijeci == recenice[j].broj_rijeci && recenice[i].duljina_recenice < recenice[j].duljina_recenice))
			{
				struct Recenica temp = recenice[i];
				recenice[i] = recenice[j];
				recenice[j] = temp;
			}
		}
	}
}

void formiraj_novi_string(struct Recenica recenice[64], int broj_recenica, char novi_string[128 * 64])
{
	int i;
	for (i = 0; i < broj_recenica; i++)
	{
		strcat(novi_string, recenice[i].najduza_rijec);
		if (i <= broj_recenica - 2)
		{
			strcat(novi_string, " ");
		}
	}
	novi_string[strlen(novi_string)] = '\0';
}

int main()
{
	struct Recenica recenice[64];
	char unesene_recenice[64][128];
	char novi_string[128 * 64];
	int broj_recenica;

	broj_recenica = unos(unesene_recenice);
	preradi_recenice(unesene_recenice, recenice, broj_recenica);
	sortiraj(recenice, broj_recenica);
	formiraj_novi_string(recenice, broj_recenica, novi_string);

	printf("Novi string: %s\n", novi_string);

	return 0;
}