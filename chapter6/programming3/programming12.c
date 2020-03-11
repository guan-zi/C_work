#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void sort(int a[], int n)
{
	int i, j, k;
	int temp;
	for (i=0; i<n-1; i++)
	{
		k=i;
		for(j=i+1; j<n; j++)
			if(a[k]>a[j])
				k=j;
		if (k!=i)
		{
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
}


int main(){
	int a[N];
	int i, j, k;

	printf("随机产生并输出源数组:\n");
	for(i=0; i<N; i++)
	{
		a[i] = rand(time(0));
		while(a[i])
		{
			a[i] = (rand()+(i+1)*100)%100;

		}
		printf("%5d", a[i]);
	}
	printf("\n");
	sort(a, N);
	printf("输出已排序的数组:");

	for(i=0; i<N; i++)
		printf("%5d", a[i]);
	printf("\n");
	return 0;
	
}
