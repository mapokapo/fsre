#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	int zbroj = 0;

	while ((c = getchar()) != '\n') {
		zbroj += atoi(&c);
	}
	printf("Zbroj je %d.\n", zbroj);
}