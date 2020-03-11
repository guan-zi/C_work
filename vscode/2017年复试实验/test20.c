#include <stdio.h>

int main()
{
    int i,sign = 1;
    float sum = 0;
    for ( i = 1; i < 11; i++)
    {
        sum += sign*((float)1/i);
        sign = -sign;
    }
    printf("%lf", sum);
}