/*
	Leo Petrovic - 2174/RR

	Zadatak 3. - Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni
	dio (float), inicijalizira niz od 10 kompleksnih brojeva i u datoteku
	kompleksni_brojevi.txt upisuju se sortirani po udaljenosti od ishodišta kompleksne
	ravnine.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct KompleksniBroj
{
	float realni;
	float imaginarni;
};

float udaljenost(struct KompleksniBroj broj)
{
	return sqrt(broj.realni * broj.realni + broj.imaginarni * broj.imaginarni);
}

int main()
{
	struct KompleksniBroj niz[10], temp;
	FILE *stream;
	int i, j;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		niz[i].realni = (float)rand() / (float)(RAND_MAX / 100);
		niz[i].imaginarni = (float)rand() / (float)(RAND_MAX / 100);
	}

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (udaljenost(niz[i]) < udaljenost(niz[j]))
			{
				temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

	stream = fopen("kompleksni_brojevi.txt", "w");
	for (i = 0; i < 10; i++)
	{
		fprintf(stream, "(%.2f, %.2f) -> %.2f\n", niz[i].realni, niz[i].imaginarni, udaljenost(niz[i]));
	}
	fclose(stream);

	return 0;
}