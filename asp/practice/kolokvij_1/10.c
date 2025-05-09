#include <stdio.h>
#include <string.h>

int provjeri(char *str, int start_index, int end_index)
{

	while (str[start_index] < 'a' || str[start_index] > 'z')
	{
		start_index++;
	}

	while (str[end_index] < 'a' || str[end_index] > 'z')
	{
		end_index--;
	}

	if (end_index - start_index < 1)
	{
		return 1;
	}

	if (str[start_index] != str[end_index])
	{
		return 0;
	}

	return provjeri(str, start_index + 1, end_index - 1);
}

int main()
{
	char buffer[256];

	printf("Unesite recenicu: ");
	gets(buffer);

	if (provjeri(buffer, 0, strlen(buffer) - 1))
	{
		printf("Recenica je palindrom!\n");
	}
	else
	{
		printf("Recenica nije palindrom.\n");
	}

	return 0;
}