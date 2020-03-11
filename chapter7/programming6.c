#include <stdio.h>
#define M 3
#define N 4

float minmium(float (*p)[N], float *min, int m, int n)
{
	int i, j;
	*min = *(*(p+0)+0);

	for (i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			if (*min > p[i][j])
				*min = p[i][j];
		}
	}
	printf("Min score: %.2f\n", *min);
}


float maxmium(float (*p)[N], float *max, int m, int n)
{
	int i, j;
	
	*max = *(*(p+0)+0);

	for (i=0; i<M; i++)
	{
		for(j=0; j<N; j++)
		{
			if (*max < p[i][j])
				*max = p[i][j];
		}
	}
	printf("Max score: %.2f\n", *max);
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
	int choice;

	void(*f[4])(float (*)[4], float *, int, int) = {printArray, minmium, maxmium, average};

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
		while(1)
		{
			
			printf("Case %d\n", k);
			printf("Enter a choice:\n");
			printf("0 Print the array of grades\n");
			printf("1 Find the minium grade\n");
			printf("2 Find the maxium grade\n");
			printf("3 Print the average on all tests for each student\n");
			printf("4 End program\n");
			printf("Input your select:");
			scanf("%d", &choice);
			if (choice==4)
				break;
			(*f[choice])(a, b, M, N);
		}
	}
	return 0;
}
