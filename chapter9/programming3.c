#include <stdio.h>
#include <stdlib.h>
#define N 5

struct worker_type
{
	char name[10];
	int name;
	int age;
	char gender;
}work[SIZE];

void save()
{
	FILE *fp;
	int i;
	if((fp=fopen("work", "wb"))==NULL)
	{
		printf("can not open file\n");
		exit(0);
	}
	for(i=0; i<SIZE; i++)
	{
		if(fwrite(&work[i], sizeof(struct work_type), 1,fp)!=1)
			printf("file write error\n");
		fclose(fp);
	}
}


int main()
{
	int i;
	FILE *fp;
	for(i=0; i<SIZE;i++)
		scanf("%s%d%d%c",&work[i].name,&work[i].num,&work[i].age, &work[i].sex);
	save();
	fp = fopen("work", "rb");
	for(i=0; i<SIZE;i++)
	{
		fread(&work[i],sizeof(struct work_type), 1, fp);
		printf("%-10s%4d%4d%2c\n", work[i].name, work[i].num, work[i].age, work[i].sex);
	}
	fclose(fp);
	return 0;
}

