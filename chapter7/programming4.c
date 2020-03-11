#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define N 5

int main()
{
	char *pchs[N];
	char str[50];
	int i;
	for(i=0; i<N; i++)
	{
		printf("请问第%d首歌的名称：", i+1);
		scanf("%s", str);
		pchs[i] = (char *)malloc(strlen(str));
		strcpy(pchs[i], str);
	}
	printf("输入的歌的名称：\n");
	for(i=0; i<N; i++)
	{
		printf("%s\n", pchs[i]);

	}

	int j,k;
	for(i=0; i<N-1;i++)
	{
		k=i;
		for (j=i+1; j<N; j++)
		{
			if(strcmp(pchs[k], pchs[j])>0)
				k=j;
		}
		if(k!=i)
		{
			strcpy(str, pchs[i]);
			strcpy(pchs[i], pchs[k]);
			strcpy(pchs[k], str);
			
			/* 
			char *p;
			p = pchs[i];
			pchs[i] = pchs[k];
			pchs[k] = p;
			*/
		
		}

	}
	
	printf("排序后歌的名称：\n");
	for (i=0; i<N; i++)
		printf("%s\n", pchs[i]);
	return 0;
}


