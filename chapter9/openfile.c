#include <stdio.h>
#include <stdlib.h>

int main()
{
	char filename[20], ch;
	FILE *fp;
	printf("Enter file name:\n");
	scanf("%s", filename);
	
	if ((fp=fopen(filename, "r")) == NULL)
	{
		printf("open file error\n");
		exit(0);
	}
	while((ch = fgetc(fp))!=EOF)
		putchar(ch);
	return 0;
}
