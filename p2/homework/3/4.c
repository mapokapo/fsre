#include <stdio.h>
#include <string.h>
#define BROJ_GRADOVA 10

/*
	Leo Petrovic, 2174/RR

	Zadatak 4. - Napisati program koji definira strukturu za zapis podataka o gradovima: ime grada
	(string), država u kojoj se nalazi (string), broj stanovnika (int), najbliža rijeka (string) i
	najbliža planina (string). Program inicijalizira podatke za 10 gradova, unosi ime rijeke i
	planine i pronalazi onaj grad kojima je to najbliža rijeka, odnosno planina (po jedan grad
	za svaki zemljopisni pojam), a ako ima više takvih gradova ispisuje se onaj koji ima
	najveći broj stanovnika. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata
	u glavnom programu.
*/

struct Grad
{
	char ime[128];
	char drzava[128];
	int broj_stanovnika;
	char najbliza_rijeka[128];
	char najbliza_planina[128];
};

void unos(struct Grad gradovi[])
{
	char ime[128], drzava[128], broj_stanovnika[128], najbliza_rijeka[128], najbliza_planina[128];
	int i;
	for (i = 0; i < BROJ_GRADOVA; i++)
	{
		printf("%d. grad:\n", i + 1);
		printf(" - unesite ime grada: ");
		fgets(ime, 128, stdin);
		sscanf(ime, "%[^\n]", gradovi[i].ime);
		printf(" - unesite drzavu u kojoj se grad nalaz: ");
		fgets(drzava, 128, stdin);
		sscanf(drzava, "%[^\n]", gradovi[i].drzava);
		printf(" - unesite broj stanovnika grada: ");
		fgets(broj_stanovnika, 128, stdin);
		sscanf(broj_stanovnika, "%d", &gradovi[i].broj_stanovnika);
		printf(" - unesite ime najblize rijeke gradu: ");
		fgets(najbliza_rijeka, 128, stdin);
		sscanf(najbliza_rijeka, "%[^\n]", gradovi[i].najbliza_rijeka);
		printf(" - unesite ime najblize planine gradu: ");
		fgets(najbliza_planina, 128, stdin);
		sscanf(najbliza_planina, "%[^\n]", gradovi[i].najbliza_planina);
	}
}

void unesi_rijeku(char rijeka[])
{
	printf("Unesite ime rijeke: ");
	fgets(rijeka, 128, stdin);
	sscanf(rijeka, "%[^\n]", rijeka);
}

void unesi_planinu(char planina[])
{
	printf("Unesite ime planine: ");
	fgets(planina, 128, stdin);
	sscanf(planina, "%[^\n]", planina);
}

struct Grad pronadji_grad_najblizi_rijeci(struct Grad gradovi[], char rijeka[])
{
	struct Grad najblizi_grad = gradovi[0];
	int i, broj_stanovnika_najblizeg_grada = 0;

	for (i = 0; i < BROJ_GRADOVA; i++)
	{
		if (strcmp(gradovi[i].najbliza_rijeka, rijeka) == 0)
		{
			if (gradovi[i].broj_stanovnika > broj_stanovnika_najblizeg_grada)
			{
				najblizi_grad = gradovi[i];
				broj_stanovnika_najblizeg_grada = gradovi[i].broj_stanovnika;
			}
		}
	}

	return najblizi_grad;
}

struct Grad pronadji_grad_najblizi_planini(struct Grad gradovi[], char planina[])
{
	struct Grad najblizi_grad = gradovi[0];
	int i, broj_stanovnika_najblizeg_grada = 0;

	for (i = 0; i < BROJ_GRADOVA; i++)
	{
		if (strcmp(gradovi[i].najbliza_planina, planina) == 0)
		{
			if (gradovi[i].broj_stanovnika > broj_stanovnika_najblizeg_grada)
			{
				najblizi_grad = gradovi[i];
				broj_stanovnika_najblizeg_grada = gradovi[i].broj_stanovnika;
			}
		}
	}

	return najblizi_grad;
}

int main()
{
	struct Grad gradovi[BROJ_GRADOVA] = {
			{"Zagreb", "Hrvatska", 792875, "Sava", "Medvednica"},
			{"Split", "Hrvatska", 178102, "Jadro", "Velebit"},
			{"Rijeka", "Hrvatska", 128735, "Rjecina", "Velebit"},
			{"Osijek", "Hrvatska", 108048, "Drava", "Papuk"},
			{"Zadar", "Hrvatska", 75000, "Sava", "Velebit"},
			{"Sarajevo", "Bosna i Hercegovina", 275524, "Babina", "Velez"},
			{"Banja Luka", "Bosna i Hercegovina", 185042, "Vrbas", "Kozara"},
			{"Tuzla", "Bosna i Hercegovina", 110979, "Neretva", "Kozara"},
			{"Mostar", "Bosna i Hercegovina", 105797, "Neretva", "Velez"},
			{"Zenica", "Bosna i Hercegovina", 110663, "Babina", "Vranica"},
	};
	struct Grad grad_najblizi_rijeci, grad_najblizi_planini;
	char rijeka[128], planina[128];

	// unos(gradovi);
	unesi_rijeku(rijeka);
	unesi_planinu(planina);
	grad_najblizi_rijeci = pronadji_grad_najblizi_rijeci(gradovi, rijeka);
	grad_najblizi_planini = pronadji_grad_najblizi_planini(gradovi, planina);

	printf("Grad najblizi rijeci '%s' je %s, a grad najblizi planini '%s' je %s.\n", rijeka, grad_najblizi_rijeci.ime, planina, grad_najblizi_planini.ime);

	return 0;
}