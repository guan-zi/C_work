#include <stdio.h>

struct st{
    int x;
    int *y;
}*p;

int dt[4] = {10, 20, 30, 40};
struct st aa[4] = {50, &dt[0], 60, &dt[1], 60, &dt[2],60, &dt[3] };
int main()
{
    p = aa;
    printf("%d", ++(p->x));
    return 0;
}