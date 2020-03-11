#include <stdio.h>
int main()
{
    struct x{char a[10]; int b;};
    printf("%ld\n", sizeof(struct x));
    return 0;
}