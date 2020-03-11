#include <stdio.h>
#include <string.h>
#define M 5
#define N 20

void fun(char (*ss)[N])
{
    int i, j, k, n[M];
    char t[N];
    for ( i = 0; i < M; i++)
    {
        n[i] = strlen(ss[i]);
    }
    for ( i = 0; i < M-1; i++)
    {
        k = i;
        for ( j = i+1; j < M; j++)
        {
            if (n[k]>n[j]) k = j;
        }
        if (k != j)
        {
            strcpy(t, ss[i]);
            strcpy(ss[i], ss[k]);
            strcpy(ss[k], t);
            n[k] = n [i];
        }
    }
}


int main()
{
    char ss[M][N] = {"shanghai", "guangzhou", "beijing", "tianjin", "cchongqing"};
    int i;
    printf("\n The original strings are:\n");
    for ( i = 0; i < M; i++)
    {
        printf("%s\n", ss[i]);
    }
    fun(ss);

    printf("\n The result:\n");
    for ( i = 0; i < M; i++)
    {
        printf("%s\n", ss[i]);
    }
    return 1;
}