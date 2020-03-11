#include <stdio.h>

int cmp(int A[], int na, int B[], int nb)
{
	int i = 0, j = 0;
	while(i<na&&j<nb&&A[i++]==B[j++]);
	--i;
	--j;
	if(i == na&& j==nb)
		return 0;
	if(i==na&&j!=nb)
		return -1;
	if(i!=na&&j==nb)
		return 1;
	if(A[i]>B[j])
		return 1;
	else
		return -1;
}
