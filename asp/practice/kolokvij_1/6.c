#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct korisnik
{
	char jmbg[13 + 1];
	char ime_prezime[40 + 1];
	float prihod;
	float porez;
};

int main()
{
	FILE *f;
	int i;
	long broj_zapisa;
	struct korisnik *korisnici;
	struct korisnik najduzniji;
	float najveci_porez = 0;

	f = fopen("podaci.dat", "rb");
	if (f == NULL)
	{
		printf("Datoteka 'podaci.dat' nije pronadjena!\n");
		return 1;
	}

	fread(&broj_zapisa, sizeof(long), 1, f);

	korisnici = malloc(sizeof(struct korisnik) * broj_zapisa);

	fread(korisnici, sizeof(struct korisnik), broj_zapisa, f);

	for (i = 0; i < broj_zapisa; i++)
	{
		if (korisnici[i].porez > najveci_porez)
		{
			najduzniji = korisnici[i];
			najveci_porez = korisnici[i].porez;
		}
	}

	printf("Broj korisnika je %d.\n", broj_zapisa);
	printf("Najduzniji korisnik je %s (JMBG: %s) sa porezom od %.2f.\n", najduzniji.ime_prezime, najduzniji.jmbg, najduzniji.porez);

	return 0;
}