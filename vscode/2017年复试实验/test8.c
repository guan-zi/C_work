# include <stdio.h>

int main()
{
    int x[3][2] = {0}, i;
    for ( i = 0; i < 3; i++)
    {
        scanf("%d", x[i]);
    }
    
    printf("%3d%3d%3d\n", x[0][0], x[0][1], x[1][0]);
}