#include<stdio.h>
#include<string.h>
#define N 5

int main()
{

	char *p[N];
	char str[N][50];
	int i;
	for(i=0; i<N; i++)
	{
		printf("请输入%d成员的姓名：",i+1);
		scanf("%s",str[i]);
		p[i]=str[i];

	
	}
	for(i=0; i<N; i++)
		printf("%s\n", p[i]);
}
