#include <stdio.h>
#include <stdlib.h>

int main()
{
	char a;
	int c=0;
	FILE *fp;
	if((fp = fopen("file1.txt", "r"))==NULL)
	{
		printf("the file don't exit!");
		exit(1);
	}
	while(a=fgetc(fp)!=EOF)
		c++;
	printf("the number is:%d\n",c);
	return 0;
}
