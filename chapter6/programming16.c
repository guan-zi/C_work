# include<stdio.h>
# define N 10

char low2captl(char ch)
{
	if(ch<'z'&&ch>'a')
		return ch-32;
}
int a[N]={'a','b','c','d','e','f','g','h','i','j'};
int b[N];
int main()
{
	int i;
	for(i=0; i<N/2; i++)
		b[i]=low2captl(a[2*i+1]);
	for(i=0; i<N/2; i++)
		printf("%c\t",b[i]);
	printf("\n");
	return 0;
}



