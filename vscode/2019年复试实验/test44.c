#include <stdio.h>
#include <math.h>


double func(double a)
{
    return pow(a, 5)-15*pow(a, 4)+85*pow(a, 3)-225*a*a+274*a-121;
}

int main()
{
    double mid, top = 2.5, bottom = 1.5;
    double result;

    while(1)
    {
        mid = (top+bottom)/2;
        result = func(mid);
        if (result>0)
        {
            bottom = mid;   
        }
        else if (result<0)
        {
            top = mid;
        }
        else
        {
            printf("%f", mid);
            return 1;
        }
    }
}