# include <stdio.h>
#define N 30

int main()
{
    char a[N] , ch;
    int c1,c2,c3=0;
    printf("请输入一个字符串：");
    scanf("%s", a);
    getchar();
    printf("输入一个字符：");
    scanf("%c", &ch);
    int i=0;
    while (a[i])
    {:
        if (a[i]>ch)
        {
            c1++;
        }
        else if (a[i] == ch)
        {
            c2++;
        }
        else
        {
            c3++;
        }
        i++;
    }
    printf("%d\n", c1);
    printf("%d\n", c2);
    printf("%d\n", c3);
    return 0;    
}