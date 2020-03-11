# include<stdio.h>


void main()
{
	int a[20]={0,1};
	int i, k=0;
	for(i=2; i<20; i++)
		a[i]= a[i-1]+a[i-2];

	for(i=20-1; i>=0; i--)
	{
		printf("%6d", a[i]);
		k++;
		if(k%10==0)
			printf("\n");
	}
}
