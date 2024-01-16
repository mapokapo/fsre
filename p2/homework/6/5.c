/*
	Leo Petrovic - 2174/RR

	Zadatak 5. - Napisati program koji iz datoteke rijeke.txt čita podatke o svim rijekama zapisanima u
	datoteci: naziv rijeke (string - pretpostaviti da se radi o jednoj riječi), izvor (string -
	pretpostaviti da se radi o jednoj riječi), ušće (string - pretpostaviti da se radi o jednoj
	riječi), duljina rijeke u kilometrima (float) i svi se podaci smještaju u dinamički alociran
	memorijski prostor odgovarajuće duljine. Nakon toga ispisuju se podaci o rijekama čiji je
	izvor ili ušće u Bosni i Hercegovini, sortirane po duljini rijeke silazno.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rijeka
{
	char *naziv;
	char *izvor;
	char *usce;
	float duljina;
};

int main()
{
	struct Rijeka *rijeke = NULL, temp;
	char linija[256], naziv_buffer[256], izvor_buffer[256], usce_buffer[256];
	int broj_rijeka, i, j;
	FILE *stream;

	stream = fopen("rijeke.txt", "r");
	if (!stream)
	{
		printf("Datoteka nije pronadjena.\n");
		return 1;
	}

	broj_rijeka = 0;
	while (!feof(stream))
	{
		rijeke = realloc(rijeke, sizeof(struct Rijeka) * (broj_rijeka + 1));

		fgets(linija, 256, stream);
		sscanf(linija, "%s %s %s %f", naziv_buffer, izvor_buffer, usce_buffer, &rijeke[broj_rijeka].duljina);

		rijeke[broj_rijeka].naziv = malloc(sizeof(char) * (strlen(naziv_buffer) + 1));
		strcpy(rijeke[broj_rijeka].naziv, naziv_buffer);

		rijeke[broj_rijeka].izvor = malloc(sizeof(char) * (strlen(izvor_buffer) + 1));
		strcpy(rijeke[broj_rijeka].izvor, izvor_buffer);

		rijeke[broj_rijeka].usce = malloc(sizeof(char) * (strlen(usce_buffer) + 1));
		strcpy(rijeke[broj_rijeka].usce, usce_buffer);

		broj_rijeka++;
	}
	fclose(stream);

	for (i = 0; i < broj_rijeka - 1; i++)
	{
		for (j = i + 1; j < broj_rijeka; j++)
		{
			if (rijeke[i].duljina < rijeke[j].duljina)
			{
				temp = rijeke[i];
				rijeke[i] = rijeke[j];
				rijeke[j] = temp;
			}
		}
	}

	printf("Rijeke sa uscem ili izvorom u BiH:\n");
	for (i = 0; i < broj_rijeka; i++)
	{
		if (strcmp(rijeke[i].izvor, "Bosna_i_Hercegovina") == 0 || strcmp(rijeke[i].usce, "Bosna_i_Hercegovina") == 0)
		{
			printf("%s - %.2fkm\n", rijeke[i].naziv, rijeke[i].duljina);
		}
	}

	free(rijeke);

	return 0;
}