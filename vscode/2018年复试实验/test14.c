#include <stdio.h>

int main()
{
    char ch[3][4] = {"123", "456", "78"}, *p[3];
    int i;
    for ( i = 0; i < 3; i++)
    {
        p[i] = ch[i];
    }
    for ( i = 0; i < 3; i++)
    {
        printf("%s", p[i]);
    }
    return 0;
}