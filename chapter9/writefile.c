#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char filename[20], ch;
	printf("Enter file name:\n");
	scanf("%s", filename);
	if ((fp=fopen(filename, "a"))==NULL)
	{
		printf("open file error!");
		exit(0);
	}
	getchar(); //接收回车符

	while((ch = getchar())!='\n')
		fputc(ch, fp);
	fclose(fp);
	printf("\n");
	if ((fp=fopen(filename, "r"))==NULL)
	{
		printf("open file error!\n");
		exit(0);
	}

	while((ch=fgetc(fp))!=EOF)
		putchar(ch);
	fclose(fp);
	return 0;
}
