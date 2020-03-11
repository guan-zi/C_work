#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 5
#define K 20
#define N 5


int main()
{
	char *article[M] = {"the","a","one","some","any"};
	char *noun[M] = {"boy","girl", "dog","town", "car"};
	char *verb[M] = {"drove", "jumped", "ran", "walked", "skipped"};
	char *preposition[M] = {"to", "from", "over", "under", "on"};
	char sentence[K][N] = {""};

	int i, m, T, n, count=0;
	printf("输入测试数据的数组：");
	scanf("%d", &T);

	while(T--)
	{
		count++;
		printf("输入产生句子数量：");
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			m = rand()%5;
			strcat(sentence[i], article[m]);
			strcat(sentence[i], " ");
			
			m = rand()%5;
			strcat(sentence[i], noun[m]);
			strcat(sentence[i], " ");
			
			m = rand()%5;
			strcat(sentence[i], verb[m]);
			strcat(sentence[i], " ");
			
			m = rand()%5;
			strcat(sentence[i], preposition[m]);
			strcat(sentence[i], ".");

			if (sentence[i][0]>='a' && sentence[i][0] <= 'z')
				sentence[i][0] -= 32;
		}
		printf("Case %d\n", count);
		for(i=0; i<n; i++)
		{
			puts(sentence[i]);
			memset(sentence[i], 0,sizeof(sentence[i])); //清空字符数组内容

		}
		printf("\n");
	}
	return 0;
}
