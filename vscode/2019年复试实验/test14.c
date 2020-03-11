#include <stdio.h>
#include <string.h>

void inverse(char str[])
{
    char m;
    int i, j, len;
    len = strlen(str);
    printf("in inverse\n");
    for ( i = 0, j= len-1; i<j; i++, j--)
    {
        m = str[i];
        str[i] = str[j];
        str[j] = m;
    }
}

int main()
{
    char str[] = "abcdefgh";
    inverse(str);
    int i, len;
    len = strlen(str);
    for ( i = 0; i<len; i++)
    {
        printf("%c\t", str[i]);
    }
    return 0;
}