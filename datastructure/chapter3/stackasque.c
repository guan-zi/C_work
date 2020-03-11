#include<stdio.h>
#define maxSize 100

typedef struct LStack
{
    int data[maxSize];
    int top;
}LStack;

int push(LStack *st1, LStack *st2, int e)
{
    if (st1->top == maxSize-1&& st2->top!= 1)
    {
        return 0;
    }
    if (st2->top == -1)
    {
        if (st1->top < maxSize-1)
        {
            st1->data[++(st1->top)] = e;
            return 1;
        }
        else
        {
            while (st1->top!=-1)
            {
                st2->data[++(st2->top)] = st1->data[(st1->top)--];
            }
            st1->top++;
            st1->data[st1->top] = e;
            return 1;
        }
        
    }
   return 0;
}


int pop(LStack *st1, LStack *st2, int *p)
{
    if (st2->top != -1)
    {
        *p = st2->data[st2->top--];
        return 1;
    }   
    else
    {
        if (st1->top != -1)
        {
            while (st1->top!=-1)
            {
                st2->data[++(st2->top)] = st1->data[(st1->top)--];
            }
            *p = st2->data[st2->top--];
            return 1;
        }
    }
    return 0;
}