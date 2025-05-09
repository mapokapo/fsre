#include <stdio.h>
#include <string.h>
#define BROJ_ADRESA 4

/*
	Leo Petrovic, 2174/RR

	Zadatak 3. - Napisati program koji definira strukturu za zapis podataka o adresama koje unosi
	korisnik: ulica (string), kućni broj (int), mjesto (string) i poštanski broj (int), unosi podatke
	za 10 adresa, dodatno unosi mjesto i formira dva niza adresa, jedan u dodatno
	unesenom mjestu i drugi izvan njega, sortirane po abecedi naziva ulice, odnosno kućnom
	broju ako je ulica ista. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata u
	glavnom programu.
*/

struct Adresa
{
	char mjesto[128];
	int postanski_broj;
	char ulica[128];
	int kucni_broj;
};

void unos(struct Adresa adrese[])
{
	char mjesto[128], postanski_broj[128], ulica[128], kucni_broj[128];
	int i;
	for (i = 0; i < BROJ_ADRESA; i++)
	{
		printf("%d. adresa:\n", i + 1);
		printf(" - unesite mjesto: ");
		fgets(mjesto, 128, stdin);
		sscanf(mjesto, "%[^\n]", adrese[i].mjesto);
		printf(" - unesite postanski broj: ");
		fgets(postanski_broj, 128, stdin);
		sscanf(postanski_broj, "%d", &adrese[i].postanski_broj);
		printf(" - unesite ulicu: ");
		fgets(ulica, 128, stdin);
		sscanf(ulica, "%[^\n]", adrese[i].ulica);
		printf(" - unesite kucni broj: ");
		fgets(kucni_broj, 128, stdin);
		sscanf(kucni_broj, "%d", &adrese[i].kucni_broj);
	}
}

void unesi_dodatno_mjesto(char dodatno_mjesto[])
{
	printf("Unesite dodatno mjesto: ");
	fgets(dodatno_mjesto, 128, stdin);
	sscanf(dodatno_mjesto, "%[^\n]", dodatno_mjesto);
}

int formiraj_dodatni_niz(struct Adresa adrese[BROJ_ADRESA], struct Adresa novi_niz[], char dodatno_mjesto[], int unutar_mjesta)
{
	int i, j = 0;
	for (i = 0; i < BROJ_ADRESA; i++)
	{
		if (strcmp(adrese[i].mjesto, dodatno_mjesto) == 0 && unutar_mjesta)
		{
			novi_niz[j] = adrese[i];
			j++;
		}
		else if (strcmp(adrese[i].mjesto, dodatno_mjesto) != 0 && !unutar_mjesta)
		{
			novi_niz[j] = adrese[i];
			j++;
		}
	}
	return j;
}

void sortiraj(struct Adresa adrese[], int duljina_niza)
{
	int i, j;

	for (i = 0; i < duljina_niza - 1; i++)
	{
		for (j = i + 1; j < duljina_niza; j++)
		{
			if (strcmp(adrese[i].ulica, adrese[j].ulica) > 0 || (strcmp(adrese[i].ulica, adrese[j].ulica) == 0 && adrese[i].kucni_broj > adrese[j].kucni_broj))
			{
				struct Adresa temp = adrese[i];
				adrese[i] = adrese[j];
				adrese[j] = temp;
			}
		}
	}
}

int main()
{
	char dodatno_mjesto[128];
	struct Adresa adrese[BROJ_ADRESA];
	struct Adresa adrese_u_mjestu[BROJ_ADRESA], adrese_izvan_mjesta[BROJ_ADRESA];
	int duljina_niza_adrese_u_mjestu, duljin_niza_adrese_izvan_mjesta, i;

	unos(adrese);
	unesi_dodatno_mjesto(dodatno_mjesto);

	duljina_niza_adrese_u_mjestu = formiraj_dodatni_niz(adrese, adrese_u_mjestu, dodatno_mjesto, 1);
	duljin_niza_adrese_izvan_mjesta = formiraj_dodatni_niz(adrese, adrese_izvan_mjesta, dodatno_mjesto, 0);

	sortiraj(adrese_u_mjestu, duljina_niza_adrese_u_mjestu);
	sortiraj(adrese_izvan_mjesta, duljin_niza_adrese_izvan_mjesta);

	printf("\nAdrese u mjestu %s:\n", dodatno_mjesto);
	for (i = 0; i < duljina_niza_adrese_u_mjestu; i++)
	{
		printf(" - %s %d, ulica %s %d\n", adrese_u_mjestu[i].mjesto, adrese_u_mjestu[i].postanski_broj, adrese_u_mjestu[i].ulica, adrese_u_mjestu[i].kucni_broj);
	}

	printf("\nAdrese izvan mjesta %s:\n", dodatno_mjesto);
	for (i = 0; i < duljin_niza_adrese_izvan_mjesta; i++)
	{
		printf(" - %s %d, ulica %s %d\n", adrese_izvan_mjesta[i].mjesto, adrese_izvan_mjesta[i].postanski_broj, adrese_izvan_mjesta[i].ulica, adrese_izvan_mjesta[i].kucni_broj);
	}

	return 0;
}
