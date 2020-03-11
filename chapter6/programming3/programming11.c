# include<stdio.h>

int main(){
	int i,j,k;
	int m, n, s;
	int T[MAX][MAX], A[MAX][MAX], B[MAX][MAX];
	
	printf("input matrix A row and col:");
	scanf("%d %d", &m, &n);
	
	printf("input matrix B col:");
	scanf("%d", &s);
	printf("input A's elements:\n");
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
		{	
			scanf("%d",&A[i][j]);
			getchar();
		}

	printf("input B's elements:\n");
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
		{	
			scanf("%d",&A[i][j]);
			getchar();
		}
	
	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			T[i][j]=0;
			for(k=0; k<s; k++)
				T[i][j] += A[i][k]*b[k][j];
			
	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{	
			printf("%d\t", T[i][j]);
		}
		printf("\n");
	}
	return 0;
}

