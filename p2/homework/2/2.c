#include <stdio.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 2. - Napisati program koji definira strukturu za zapis podataka o vozilima: proizvođač
	(string), model (string), snaga u kWh (int) i cijena (float). Program inicijalizira podatke za
	5 vozila, od korisnika traži podatke o maksimalnoj snazi i minimalnoj cijeni vozila koje
	korisnik traži te mu ispisuje podatke o svim vozilima koja zadovoljavaju unesene
	podatke.
*/

struct vozilo
{
	char proizvodjac[32];
	char model[32];
	int snaga;
	float cijena;
};

int main()
{
	int maksimalna_snaga;
	float minimalna_cijena;
	int i;
	struct vozilo vozila[5] =
			{
					{
							"Opel",
							"Astra",
							330,
							8000,
					},
					{
							"Fiat",
							"Marea",
							160,
							3000,
					},
					{
							"BMW",
							"IX",
							630,
							50000,
					},
					{
							"Mercedes",
							"EQS Sedan",
							260,
							95000,
					},
					{
							"Volkswagen",
							"Golf 4",
							75,
							10000,
					},
			};

	printf("Unesite maksimalnu snagu vozila kojeg trazite: ");
	scanf("%d", &maksimalna_snaga);

	printf("Unesite minimalnu cijenu vozila kojeg trazite: ");
	scanf("%f", &minimalna_cijena);

	printf("Vozila koja zadovoljavaju vase uvjete su: \n");
	for (i = 0; i < 5; i++)
	{
		if (vozila[i].snaga <= maksimalna_snaga && vozila[i].cijena >= minimalna_cijena)
		{
			printf(" - %s %s (%.2f€, %d kW)\n", vozila[i].proizvodjac, vozila[i].model, vozila[i].cijena, vozila[i].snaga);
		}
	}

	return 0;
}