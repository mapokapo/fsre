#include <stdio.h>

int main(void)
{
	short a, b;
	short *p;

	p = &a;
	*p = 7;
	b = a;

	printf("%d %d %d\n", a, b, *p);

	return 0;
}