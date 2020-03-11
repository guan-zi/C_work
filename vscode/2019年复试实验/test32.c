#include <stdio.h>
int main()
{
    int a, b, k=10, m=6, *p1=&k, *p2=&m;
    a = p1==m;
    b = (*p1)/(*p2) + 7;
    printf("a=%d, b=%d", a, b);
}