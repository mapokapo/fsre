#include <stdio.h>
#include <string.h>

int main()
{
	char a[100] = "Hello, world!";
	char b[100];
	strncpy(b, a + 5, 10 - 5 + 1);
	printf("%s\n", b); // Hello
}