#include <stdio.h>

int isComNum(int n)
{
    int i, sum=0;
    for ( i = 1; i <= n/2; i++)
    {
        if(n%i == 0)
            sum += i;
    }
    if(sum == n)
        return 1;
    else
        return 0;
}


int main()
{
    int i;
    for ( i = 1; i <= 1000; i++)
    {
        if(isComNum(i))
            printf("%i\t", i);
    }
    return 0;
}
