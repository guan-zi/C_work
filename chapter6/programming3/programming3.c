# include <stdio.h>
//# include "usermath.h"
# include <string.h>

char *d2other(int d, int base);
//int power(int base, int count);


int main()
{
	
	int n, b, i;
	int base[20]={0};
	printf("input a decimal number:\n");
	scanf("%d", &n);
	printf("input transfer base:16,8,2:");
	scanf("%d", &b);

	strcpy(base, d2other(n,b));
	for (i=0; i<=strlen(base)-1; i++)
		printf("%c", base[i]);
	printf("\n");
	return 0;
}


char *d2other(int d, int base)
{
	char bs[20]={0};
	int shang = d;
	int count;
	int round;
	while(shang>0)
	{
		shang = shang/base;
		count++;
	}
	
	shang = d;
	while(shang>0)
	{
		round=shang%base;
		if(round<10)
			bs[count-1]=round+'0';
		else
			bs[count-1]=round+'a'-10;
		shang = d/base;
		count--;
	}

	return bs;
}



