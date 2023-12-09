#include <stdio.h>
#include <string.h>

/*
	Leo Petrovic 2174/RR

	Zadatak 3. - Napisati program koji unosi rečenicu i na osnovu nje formira niz cijelih brojeva tako da
	članovi niza predstavljaju ASCII kodove znakova unesene rečenice.
*/

int main()
{
	char recenica[256];
	int cijeli_brojevi[256];
	int i;

	printf("Unesite recenicu: ");
	gets(recenica);

	for (i = 0; i < strlen(recenica); i++)
	{
		cijeli_brojevi[i] = recenica[i];
	}

	printf("ASCII kodovi znakova recenice su:");
	for (i = 0; i < strlen(recenica); i++)
	{
		printf(" %d", cijeli_brojevi[i]);
	}
	printf("\n");

	return 0;
}