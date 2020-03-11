#include <stdio.h>
#include <string.h>


void juliuscode(char a[], int m)
{
    int len, i;
    len = strlen(a);
    for ( i = 0; i < len; i++)
    {
        if (a[i]>='A'&&a[i]<='Z')
        {
            a[i] = (a[i]-'A'+m)%26 + 'A';
        }
    }
}


int main()
{
    char a[] = "ASDFSAFGFDHJFGH";
    juliuscode(a, 3);
    printf("%s\n", a);
    return 1;
}