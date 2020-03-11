#include <stdio.h>

void sort(int a[], int n)
{
    int t, k, i, j;
    for ( i = 0; i < n-1; i++)
    {
        k = i;
        for ( j = i+1; j < n; j++)
        {
            if (a[i]>a[j])
                k = j;
        }
       if (k != i)
       {
           t = a[i];
           a[i] = a[k];
           a[k] = t;
       }
        
    }
}


int main()
{
    int b[10], i;
    printf("enter the array \n");
    for ( i = 0; i < 10; i++)
    {
        scanf("%d", &b[i]);
    }
   
    for ( i = 0; i < 10; i++)
    {
        printf("%d  ", b[i]);
    }
    printf("\n");

    sort(b, 10);
    printf("the sorted array:\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d  ", b[i]);
    }
    printf("\n");
    return 1;
}