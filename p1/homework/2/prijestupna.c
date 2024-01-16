#include <stdio.h>

int main() {
	int godina;
	int p = 0;

	printf("Unesite godinu: ");
	scanf("%d", &godina);

	p = godina % 4 != 0 || godina % 100 == 0 && godina % 400 != 0 ? 0 : 1;

	printf("Godina %d ima %d dana.\n", godina, p == 0 ? 365 : 366);
}