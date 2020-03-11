#include <stdio.h>
#define M 3
#define N 4

float minmium(float *p, int n)
{
	float min = 0;
	float *p_end;
	p_end = p+n-1;
	min = *p;

	for (++p; p<p_end; p++)
	{
		if(min>*p)
			min = *p;
	}
	return min;
}


float maxmium(float *p, int n)
{
	float max = 0;
	float *p_end;
	p_end = p+n-1;
	max = *p;

	for (++p; p<p_end; p++)
	{
		if(max < *p)
			max = *p;
	}
	return max;
}


void average(float (*p)[N], float b[], int m, int n)
{
	int i, j;
	float sum = 0;
	for (i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			sum += *(*(p+i)+j);
		}
		b[i] = sum;
		sum = 0;
	}
}


void printArray(float (*p)[N], float b[], int m, int n)
{
	int i, j;
	printf("No\tkc1\tkc2\tkc3\tkc4\taverage_score\n");
	for(i=0; i<m; i++)
	{
		printf("%d\t", i+1);
		for(j=0; j<n; j++)
		{
			printf("%0.2f\t", p[i][j]);
		}
		printf("%0.2f\n", b[i]);
	}

}


int main()
{
	float a[M][N];
	float b[M];
	int T, i, j, k=0;
	printf("输入测试的数据数组：");
	scanf("%d", &T);
	while(T--)
	{
		k++;
		for(i=0; i<M;i++ )
		{
			for(j=0; j<N; j++)
				scanf("%f", &a[i][j]);
		}
		printf("Case %d\n", k);
		printf("Min score: %.2f\n", minmium(*a, M*N));
		printf("Max score: %.2f\n", maxmium(*a, M*N));
		average(a, b, M, N);
		printArray(a, b, M, N);
	}
	return 0;
}
