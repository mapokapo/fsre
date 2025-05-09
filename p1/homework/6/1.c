#include <stdio.h>

/*
	Leo Petrovic - 2174/RR

	Zadatak 1. - Napisati program koji unosi 20 znakova i u funkciji ispis() ispisuje ih na način da za svako
	malo slovo engleskog alfabeta ispiše odgovarajuće veliko i obratno, dok sve znakove koji
	nisu slova engleskog alfabeta ispisuje kako su i uneseni.
*/

void ispis(char znakovi[20])
{
	int i;

	for (i = 0; i < 20; i++)
	{
		char znak = znakovi[i];
		if (znak >= 'a' && znak <= 'z')
		{
			printf("%c\n", znak - 32);
		}
		else if (znak >= 'A' && znak <= 'Z')
		{
			printf("%c\n", znak + 32);
		}
		else
		{
			printf("%c\n", znak);
		}
	}
}

int main()
{
	char znakovi[20];
	int i;

	for (i = 0; i < 20; i++)
	{
		printf("Unesite znak: ");
		scanf(" %c", &znakovi[i]);
	}

	ispis(znakovi);

	return 0;
}