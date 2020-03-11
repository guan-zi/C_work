#include <stdio.h>
int main()
{
    int a[4][4] = {{1,2,-3,-5},{0, 9, -2,4},{23, 21, 0, 24},{-31, 32,33,0}};
    int i, j, s = 0;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if (a[i][j]<0)
            {
                continue;
            }
            if (a[i][j]==0)
            {
                break;
            }
            s = s+a[i][j];
        }
        
    }
    printf("%d\n", s);
    return 0;
}