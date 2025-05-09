#include <stdio.h>

int index_max(int A[], int i, int n)
{
	int imax;
	if (i >= n)
		return n - 1;
	imax = index_max(A, i + 1, n);
	if (A[i] > A[imax])
	{
		return i;
	}
	return imax;
}

int main()
{
	int A[] = {5, 7, 2, 1, 6, 3, 10, 9, 8, 4};

	int i = index_max(A, 0, 10);

	printf("Najveci broj je %d.\n", A[i]);

	return 0;
}