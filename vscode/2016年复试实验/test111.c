#include <stdio.h>

void main()
{
    int x, y, z;
    scanf("%d,%d,%d", &x, &y, &z);
    if (x<y)
    {
        if (y<z)
        {
            printf("%d\n", z);
        }
        else
        {
            printf("%d\n", y);
        }
    }
    else if(x<z)
    {
        printf("%d\n", z);
    }
    else
        printf("%d\n", z);
    
}