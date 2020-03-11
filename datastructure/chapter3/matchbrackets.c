#include <ctype.h>
#include <stdio.h>
#define maxSize 100


int match(char exp[], int n)
{
    char stack[maxSize];
    int top = -1;
    int i;
    for ( i = 0; i < n; i++)
    {
        if (exp[i]=='(')
        {
            stack[++top] = exp[i];
        }
        if (exp[i]==')')
        {
            if (top==-1)
            {
                return 0;
            }
            top--;
        }
    }
   if (top==-1)
   {
    return 1;   /* code */
   }
    return 0;
}


int Op(int a,char op, int b)
{
    if (op == '+')
    {
        return a+b;/* code */
    }
    if (op == '-')
    {
        return a-b;/* code */
    }
    if (op == '*')
    {
        return a*b;   /* code */
    }
    if (op == '/')
    {
        if (b==0)
        {
            printf("error, division can't be 0.\n");
            return 0;/* code */
        }
        return a/b;
    }
}


int com(char s[])
{
    int stack[maxSize];
    int a, b,c,i, top = -1;
    char op;

    for ( i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            stack[++top] = s[i] - '0';
        }
        else
        {
            op = s[i];
            b = stack[top--];
            a = stack[top--];
            c = Op(a,op, b);
            stack[++top] = c;
        }
    }
    return stack[top];   
}
