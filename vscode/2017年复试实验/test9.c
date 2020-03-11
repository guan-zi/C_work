#include <stdio.h>

void f(int);
main()
{
    void f(int);
    f(5);
}

void f(int n)
{
    printf("%d\n", n);
    return;
}