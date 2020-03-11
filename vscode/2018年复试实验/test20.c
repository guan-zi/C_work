#include <stdio.h>

int main()
{
    int n, m = 1;
    int i;
    printf("enter the number you want to multiply:\n");
    scanf("%d", &n);
    for ( i = 1; i <= n; i++)
    {
        m *=i;
        while(!(m%10))
        {
            m = m/10;
            printf("%d\n", m);
        }
        m = m%10; 
    }
    printf("%d\n", m);
    return 1; 
}