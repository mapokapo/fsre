#include <stdio.h>

struct korisnik
{
	char jmbg[13 + 1];
	char ime_prezime[40 + 1];
	float prihod;
	float porez;
};

int main()
{
	struct korisnik entries[] = {
			{"1234567890123", "John Doe", 5000.0, 1000.0},
			{"9876543210987", "Jane Smith", 6000.0, 1200.0},
			{"4567890123456", "Bob Johnson", 4000.0, 800.0}};
	long numEntries = sizeof(entries) / sizeof(entries[0]);

	FILE *file = fopen("podaci.dat", "wb");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		return 1;
	}

	fwrite(&numEntries, sizeof(numEntries), 1, file);
	fwrite(entries, sizeof(struct korisnik), numEntries, file);

	fclose(file);

	return 0;
}
