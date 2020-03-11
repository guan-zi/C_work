#include <stdio.h>
int main()
{
    int i, j;
    for ( i = 10; i < 100000; i++)
    {
       for ( j = 1; j < 13; j++)
       {
           if (i*i+168 == (i+j)*(i+j))
           {
               printf("%d", i*i-100);
               return 1;
           }
           
       }
       
    }
    return 0;
}