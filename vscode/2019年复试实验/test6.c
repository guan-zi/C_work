#include <stdio.h>
#define M(x, y, z) x*y+z

int main()
{
    int a = 4, b=1, c=2;
    printf("%d", M(a+b, c+a, b+c));
    return 0;
}