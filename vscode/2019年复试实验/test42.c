#include <stdio.h>
#define M 5
#define N 5

float compare(int a[M][N], int b[M][N])
{
    int i, j;
    int count = 0;
    for ( i = 0; i < M; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if (a[i][j] == b[i][j])
            {
                count ++;
            }
        }
    }
    return (float)count/(M*N)
}