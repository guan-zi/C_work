#include <stdio.h>
#include <time.h>
#define maxSize 100


typedef struct Sqstack
{
    int data[maxSize];
    int top;
}Sqstack;


int initStack(Sqstack *st)
{
    st->top = -1;
    return 1;
}


int pushStack(Sqstack *st, int e)
{
    if (st->top == maxSize-1)
    {
        printf("stack overflaw");
        return 0;
    }
    st->data[++(st->top)] = e;
    return 1;
}


int popStack(Sqstack *st, int *p)
{
    if (st->top==-1)
    {
        printf("stack is empty\n");
        return 0;
    }
    *p = st->data[(st->top)--];
    return 1;
}

int isEmpty(Sqstack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    return 0;
}


int isFull(Sqstack *st)
{
    if (st->top == maxSize-1)
    {
        return 1;
    }
    return 0;
}

