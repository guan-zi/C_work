# include <stdio.h>
#define N 10

int main()
{
	int T, n, i, j;
	long a[N][N], cj;
	cj=1;
	printf("input row number:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("input matrix %d row %d col element:", i+1, n);
		for(j=0; j<n; j++)
			scanf("%ld", &a[i][j]);

	}
	
	for(i=0; i<n; i++)
		cj *=a[i][i];
	if(n%2==0 && cj!=0)
		cj/=a[n/2][n/2];

	printf("multiply value:%ld", cj);
	return 0;
}
