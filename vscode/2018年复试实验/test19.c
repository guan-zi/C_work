#include <stdio.h>
#include <string.h>
#define maxSize 10
void reverse(char ch[], int n)
{
    int i, j;
    char temp;
    for ( i = 0, j = n-1; i < j; i++, j--)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }
}


int digit2char(char ch[], int n)
{
    int i=0;
    while (n)
    {
        ch[i] = n%10+'0';
        n = n/10;
        i++;
    }
//    reverse(ch, strlen(ch));
    return i;
}

int main()
{
    int m, n;
    char a[maxSize];
    printf("enter a number:\n");
    scanf("%d", &m);
    n = digit2char(a, m);

    // printf("%s", a);
    reverse(a, n);
    printf("%s", a);
    return 1;
}