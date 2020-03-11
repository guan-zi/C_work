#include <stdio.h>

int main()
{
    int i, j, x=0;
    for ( i = 0; i < 2; i++)
    {
        x++;
        for (j = 0; j <= 5; j++)
        {
            if (j%2)
            {
                continue;
            }
            x++;
        }
    }
    
    printf("x=%d\n", x);
    return 0;
}