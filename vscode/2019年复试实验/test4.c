#include <stdio.h>

void fun(int a, int b, int c)
{
    c = a+b*a+c;
}

int main()
{
    int c = 22;
    fun(6, 3, c);
    printf("%d", c);
    return 0;
}
