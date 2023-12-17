#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double funkcija(double n, int k)
{
	if (k == 0)
		return 1;
	if (k == 1)
		return n;

	if (k <= -1)
		return 1 / (n * funkcija(n, abs(k) - 1));

	return n * funkcija(n, k - 1);
}

int main()
{
	int a, b;

	printf("Unesite a i b: ");
	scanf("%d %d", &a, &b);

	printf("%d^%d=%.5f\n", a, b, funkcija(a, b));

	return 0;
}