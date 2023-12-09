/*
	Leo Petrovic 2174/RR

	Zadatak 3. - Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni
	dio (float) i iz datoteke kompleksni_brojevi.txt čita podatke za 10 kompleksnih brojeva i
	smješta ih u dinamički alociran memorijski prostor odgovarajuće duljine. Nakon toga
	unosi se dodatni kompleksni broj i ispisuje onaj od učitanih kompleksnih brojeva koji je
	od dodatnog broja najudaljeniji u kompleksnoj ravnini.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct KompleksniBroj
{
	float realni;
	float imaginarni;
};

float udaljenost(struct KompleksniBroj a, struct KompleksniBroj b)
{
	return sqrt(pow(a.realni - b.realni, 2) + pow(a.imaginarni - b.imaginarni, 2));
}

int main()
{
	struct KompleksniBroj *brojevi = NULL, dodatni, najdalji;
	int broj_linija, i;
	float udaljenost_najdaljeg;
	FILE *stream;

	stream = fopen("kompleksni_brojevi.txt", "r");
	if (stream == NULL)
	{
		printf("Datoteka nije pronadjena.\n");
		return 1;
	}

	broj_linija = 0;
	while (!feof(stream))
	{
		brojevi = realloc(brojevi, sizeof(struct KompleksniBroj) * (broj_linija + 1));
		fscanf(stream, "(%f, %f)\n", &brojevi[broj_linija].realni, &brojevi[broj_linija].imaginarni);
		broj_linija++;
	}
	fclose(stream);

	printf("Unesite dodatni kompleksni broj u formatu (R, I): ");
	scanf("(%f, %f)", &dodatni.realni, &dodatni.imaginarni);

	najdalji = brojevi[0];
	udaljenost_najdaljeg = 0;

	for (i = 0; i < broj_linija; i++)
	{
		float u = udaljenost(brojevi[i], dodatni);
		if (u > udaljenost_najdaljeg)
		{
			najdalji = brojevi[i];
			udaljenost_najdaljeg = u;
		}
	}

	printf("Broj najdalji od dodatno unesenog broja je: (%.2f, %.2f) => %.2f\n", najdalji.realni, najdalji.imaginarni, udaljenost(najdalji, dodatni));

	return 0;
}