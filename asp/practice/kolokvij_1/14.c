#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int mbr;
	char ime[21];
	char prezime[21];
} Zapis;

Zapis *trazi(FILE *f, int mbr)
{
	Zapis *zap = malloc(sizeof(Zapis));

	fseek(f, (mbr - 1) * sizeof(Zapis), SEEK_SET);
	fread(zap, sizeof(Zapis), 1, f);

	if (zap->mbr == 0)
	{
		return NULL;
	}
	else
		return zap;
}

Zapis *bin_trazi(Zapis lista[], int len, int mbr)
{
	int min, mid, max;

	min = 0;
	max = len - 1;

	while (min <= max)
	{
		mid = (min + max) / 2;

		if (lista[mid].mbr < mbr)
		{
			min = mid + 1;
		}
		else if (lista[mid].mbr > mbr)
		{
			max = mid - 1;
		}
		else
		{
			return lista + mid;
		}
	}

	return NULL;
}

int main()
{
	FILE *in, *out;
	int br_zapisa, i;
	char buffer[256];
	Zapis temp;
	Zapis *lista;
	lista = NULL;
	Zapis z0 = {0};

	in = fopen("file.txt", "r");
	if (in == NULL)
		return 1;
	out = fopen("file.dat", "w+b");
	if (out == NULL)
		return 1;

	br_zapisa = 0;
	while (fgets(buffer, 256, in))
	{
		sscanf(buffer, "%d %s %s", &temp.mbr, temp.ime, temp.prezime);
		lista = realloc(lista, sizeof(Zapis) * (br_zapisa + 1));
		lista[br_zapisa++] = temp;
	}

	for (i = 0; i < 9; i++)
	{
		fwrite(&z0, sizeof(Zapis), 1, out);
	}

	for (i = 0; i < br_zapisa; i++)
	{
		fseek(out, (lista[i].mbr - 1) * sizeof(Zapis), SEEK_SET);
		fwrite(lista + i, sizeof(Zapis), 1, out);
	}
	fclose(in);

	printf("Postoji: %s\n", trazi(out, 5) == NULL ? "NE" : "DA");
	printf("Postoji: %s\n", bin_trazi(lista, br_zapisa, 5) == NULL ? "NE" : "DA");
	printf("Postoji: %s\n", trazi(out, 0) == NULL ? "NE" : "DA");
	printf("Postoji: %s\n", bin_trazi(lista, br_zapisa, 0) == NULL ? "NE" : "DA");

	return 0;
}