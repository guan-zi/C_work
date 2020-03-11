#include <stdio.h>


int main()
{
    int m, n;
    printf("intput value of m:\n");
    scanf("%d", &m);
    printf("intput value of n:\n");
    scanf("%d", &n);
    while (m!=n)
    {
        if (m>n)
        {
            m  = m-n;
        }
        else
        {
            n = n-m;
        }
    }
    
    printf("the max primer is: %d\n", m);
    return 1;
}