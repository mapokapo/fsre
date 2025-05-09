#include <stdio.h>

/*
	Leo Petrovic - 2174/RR

	Zadatak 3. - Napisati program koji u funkciji unos() unosi 20 cijelih brojeva, u funkciji par_nepar()
	raspoređuje ih u dva niza brojeva, tj. parne smješta u jedan, a neparne u drugi niz. Oba
	niza ispisuju se u glavnom programu.
*/

void par_nepar(int brojevi[20], int parni[20], int neparni[20], int *broj_parnih, int *broj_neparnih)
{
	int i;
	int parni_i = 0, neparni_i = 0;

	for (i = 0; i < 20; i++)
	{
		if (brojevi[i] % 2 == 0)
		{
			parni[parni_i] = brojevi[i];
			parni_i++;
		}
		else
		{
			neparni[neparni_i] = brojevi[i];
			neparni_i++;
		}
	}

	*broj_parnih = parni_i;
	*broj_neparnih = neparni_i;
}

void unos(int brojevi[20])
{
	int i;

	for (i = 0; i < 20; i++)
	{
		printf("Unesite broj: ");
		scanf("%d", &brojevi[i]);
	}
}

int main()
{
	int brojevi[20];
	int parni_niz[20];
	int neparni_niz[20];
	int broj_parnih, broj_neparnih, i;

	unos(brojevi);

	par_nepar(brojevi, parni_niz, neparni_niz, &broj_parnih, &broj_neparnih);

	printf("Parni brojevi:\n");
	for (i = 0; i < broj_parnih; i++)
	{
		printf(" - %d\n", parni_niz[i]);
	}
	printf("Neparni brojevi:\n");
	for (i = 0; i < broj_neparnih; i++)
	{
		printf(" - %d\n", neparni_niz[i]);
	}

	return 0;
}