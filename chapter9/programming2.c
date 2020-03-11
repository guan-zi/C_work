#include <stdio.h>
#include <stdlib.h>


int main()
{
	FILE *fp1, *fp2;
	char file1[20], file2[20], s[10];
	printf("Enter filename1:");
	scanf("%s", file1);
	printf("Enter filename2:");
	scanf("%s", file2);

	if((fp1=fopen(file1,"r"))==NULL)
	{
		printf("file1 open error.\n");
		exit(0);
	}
	if((fp2=fopen(file2,"w"))==NULL)
	{
		printf("file2 open error.\n");
		exit(0);
	}
	while(fgets(s, 10, fp1)!=NULL)
		fputs(s, fp2);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
