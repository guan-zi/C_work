#include <stdio.h>

int main()
{
    int x = 1, y = 0, a= 0, b=0;
    switch(x)
    {
        case 1: switch (y)
        {
        case 0:
            a++;
            break;//break 仅跳出此处switch
        case 1: 
            b++;
            break;
        }//继续执行
        case 2: a++; b++; break;
        case 3: a++; b++; break;
    }
    printf("a=%d, b=%d\n", a, b);
}