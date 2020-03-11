#include <stdio.h>

int main()
{
    int i, a[5], maxvalue, minvalue, psmax=0, psmin = 0;
    for ( i = 0; i <5; i++)
    {
        scanf("%d", &a[i]);
    }
    maxvalue = a[0];
    minvalue = a[0];
    for ( i = 0; i < 5; i++)
    {
        if (a[i]<minvalue)
        {
         minvalue = a[i];
         psmin = i;
        }
        if (a[i]>maxvalue)
        {
            maxvalue = a[i];
            psmax = i;
        }
    }
    a[psmax] = minvalue;
    a[psmin] = maxvalue;
    printf("最小数的位置：%d\n",psmin);
    printf("最大值的位置: %d\n", psmax);
    for ( i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}