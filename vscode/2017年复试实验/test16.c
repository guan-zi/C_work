#include <stdio.h>
#define N 4

int fun(int t[][N], int n)
{
    int i, sum;
    sum = 0;
    for ( i = 0; i < n; i++)
    {
        sum += t[i][i];
    }
    for ( i = 0; i < n; i++)
    {
        sum += t[i][n-i-1];
    }
    return sum;
    
}
int main()
{
    int t[][N] = {21, 2,13, 24, 25, 16, 47,38, 29, 11, 32, 54, 42, 21, 3, 10}, i, j;
    printf("\nThe original data:\n");
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            printf("%4d", t[i][j]);
        }
        printf("\n");
    }
    
    printf("The result is:    %d", fun(t, N));
    return 1;
}