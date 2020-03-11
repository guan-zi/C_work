#include <stdio.h>
#define N 5

void sort(int *p,int n)
{
	int i, j;
	int temp;
	int flag;
	for(i=0; i<n-1; i++)
	{
		flag = 0;
		for(j=i+1; j<n; j++)
			if(p[i]>p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				flag = 1;
			}
		if(flag==0)
			break;
	}
}


int main()
{
	int i;
	int a[N];
	for(i=0; i<N; i++)
		scanf("%d", a+i);
	int *p=a;
	sort(p, N);
	for(i=0; i<N; i++)
		printf("%d", p[i]);
	printf("\n");
	return 0;
}
