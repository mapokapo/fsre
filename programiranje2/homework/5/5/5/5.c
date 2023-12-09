/*
	Leo Petrovic - 2174/RR

	Zadatak 5. - Napisati program koji iz datoteke drzave.txt čita podatke o svim državama zapisanima u
	datoteci: naziv države (string - pretpostaviti da se radi o jednoj riječi), glavni grad (string -
	pretpostaviti da se radi o jednoj riječi), kontinent (string - pretpostaviti da se radi o
	jednoj riječi), površina države u kvadratnim kilometrima (int) i broj stanovnika (int).
	Nakon toga ispisuju se podaci o azijskim državama sa manje od 10.000.000 stanovnika
	sortirani po broju stanovnika države uzlazno.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Drzava
{
	char *naziv;
	char *glavni_grad;
	char *kontinent;
	int povrsina;
	int broj_stanovnika;
};

int main()
{
	struct Drzava *drzave = NULL, temp;
	char linija[256], naziv_buffer[256], glavni_grad_buffer[256], kontinent_buffer[256];
	int broj_drzava, i, j;
	FILE *stream;

	stream = fopen("./5/drzave.txt", "r");
	if (!stream)
	{
		printf("Datoteka nije pronadjena.\n");
		return 1;
	}

	broj_drzava = 0;
	while (!feof(stream))
	{
		drzave = realloc(drzave, sizeof(struct Drzava) * (broj_drzava + 1));

		fgets(linija, 256, stream);
		sscanf(linija, "%s %s %s %d %d", naziv_buffer, glavni_grad_buffer, kontinent_buffer, &drzave[broj_drzava].povrsina, &drzave[broj_drzava].broj_stanovnika);

		drzave[broj_drzava].naziv = malloc(sizeof(char) * (strlen(naziv_buffer) + 1));
		strcpy(drzave[broj_drzava].naziv, naziv_buffer);

		drzave[broj_drzava].glavni_grad = malloc(sizeof(char) * (strlen(glavni_grad_buffer) + 1));
		strcpy(drzave[broj_drzava].glavni_grad, glavni_grad_buffer);

		drzave[broj_drzava].kontinent = malloc(sizeof(char) * (strlen(kontinent_buffer) + 1));
		strcpy(drzave[broj_drzava].kontinent, kontinent_buffer);

		broj_drzava++;
	}
	fclose(stream);

	for (i = 0; i < broj_drzava - 1; i++)
	{
		for (j = i + 1; j < broj_drzava; j++)
		{
			if (drzave[i].broj_stanovnika > drzave[j].broj_stanovnika)
			{
				temp = drzave[i];
				drzave[i] = drzave[j];
				drzave[j] = temp;
			}
		}
	}

	printf("Azijske drzave sa manje od 10M stanovnika:\n");
	for (i = 0; i < broj_drzava; i++)
	{
		if (strcmp(drzave[i].kontinent, "Azija") == 0 && drzave[i].broj_stanovnika < 10000000)
		{
			printf("%s (Gl. grad: %s, kontinent: %s) - %d stanovnika, povrsina: %d\n", drzave[i].naziv, drzave[i].glavni_grad, drzave[i].kontinent, drzave[i].broj_stanovnika, drzave[i].povrsina);
		}
	}

	free(drzave);

	return 0;
}