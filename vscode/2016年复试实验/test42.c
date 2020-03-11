#include <stdio.h>
#include <math.h>


int istriangle(int a, int b, int c)
{
    if((a+b)>c&&(b+c)>a&&(a+c)>b)
        return 1;
    else
        return 0;
}

void func(int *a, int *b, int *c)
{
    int temp;
    if(*a<*b)
    {
        if(*b<*c)
            return ;
        else
        {
            temp = *b;
            *b = *c;
            *c = temp;
        }
    }
    else
    {
        temp = *a;
        *a = *b;
        *b = temp;
        if(*b<*c)
            return ;
        else
        {
            temp = b;
            b = c;
            c = temp;
        }
    }
}


void judgeangle(int a, int b, int c)
{
    if(a==b || b== c|| c==a)
    {
        if (a==b && a==c)
            printf("等边三角形");
        else
        {
            if(a*a+b*b == c*c)
                printf("等腰直角三角形");
            else
                printf("等腰三角形");
        }
    }
    else if(a*a+b*b==c*c)
        printf("直角三角形");
    else
        printf("一般三角形");
}

int main()
{
    int a, b, c;
    printf("input the length of the triangle's side:a,b,c\n");
    scanf("%d,%d,%d\n", &a, &b, &c);
    func(&a, &b, &c);
    if (istriangle(a, b, c))
    {
        judgeangle(a, b, c);
        printf("area is: %f", sqrt((a+b+c)*(b+c)*(a+c)*(b+c)));
        return 1;
    }
    else
    {
        printf("not triangle!");
        return 0;
    }
}