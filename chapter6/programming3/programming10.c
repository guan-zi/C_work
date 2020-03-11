# include <stdio.h>
#define MAX 10


int main()
{
	int i, j,T, m,n, k=0;
	int a[MAX][MAX], b[MAX][MAX];
	printf("输入测试数据的数组：");
	scanf("%d", &T);

	while(T--)
	{
		k++;
		printf("输入矩阵的行数和列数，用空格分隔：");
		scanf("%d %d", &m,&n);
		for(i=0; i<m; i++)
		{
			printf("输入矩阵的第%d行的%d个数据", i+1,n);
			for(j=0; j<n;j++)
				scanf("%d", &a[i][j]);
		}

		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
				b[j][i] = a[i][j];
		}

		printf("case %d\n", k);
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
				b[j][i] = a[i][j];
		for(i=0; i<m; i++)
		{
			for(j=0; j<n; j++)
				printf("%d\t", b[j][i]);
			printf("\n");
		}
	return 0;
}
