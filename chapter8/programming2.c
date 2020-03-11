#include <string.h>
#include <stdio.h>
#define N 5

struct user
{
	char name[20];
	char num[10];
};

int main()
{
	struct user users[N], temp;
	int i,j,k;
	for(i=0;i<N;i++)
	{
		gets(users[i].name);
		gets(users[i].num);
	}
	for(i=0; i<4; i++)
	{
		k=i;
		for(j=i+1;j<5;j++)
		{
			if(strcmp(users[k].name, users[j].name)>0)
				k=j;
			temp = users[k];
			users[k]=users[i];
			users[i] = temp;
		}
	}
	for (i=0; i<5; i++)
		printf("%s,%s\n", users[i].num, users[i].name);
	return 0;
}
