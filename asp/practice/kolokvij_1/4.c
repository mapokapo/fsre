#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char jmbg[13];
	char dd[3], mm[3], gg[3];

	printf("Unesite JMBG: ");
	scanf("%s", jmbg);

	strncpy(dd, jmbg, 2);
	dd[2] = '\0';
	strncpy(mm, jmbg + 2, 2);
	mm[2] = '\0';
	strncpy(gg, jmbg + 5, 2);
	gg[2] = '\0';

	printf("%s.%s.%s\n", dd, mm, gg);

	return 0;
}