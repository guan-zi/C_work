# include <stdio.h>

void func(int **s)
{
    int j;
    for ( j = 0; j < 10; j++)
    {
        *s[j] = 2*j;
    }
    printf("%ld\n", sizeof(*s));
}

int main(void)
{
    int i;
    int str[10];
    for ( i = 0; i < 10; i++)
    {
        str[i] = i;
        printf("%d", str[i]);
    }
    printf("\n");
    printf("%ld\n", sizeof(str));
    func(str);
    for ( i = 0; i < 10; i++)
    {
        printf("%d", str[i]);
    }
    printf("\n");
    return 0;
 
}