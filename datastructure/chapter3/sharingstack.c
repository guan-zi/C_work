#include <stdio.h>
#define maxSize 100

typedef struct
{
    int data[maxSize];
    int top[2];
}Dstack;


int initStack(Dstack *st)
{
    st->top[1] = maxSize;
    st->top[0] = -1;
    return 1;
}


int istuefull(Dstack *st)
{
    if (st->top[0] == st->top[1]-1)
    {
        return 1;
    }
    return 0;
}


int enStack(Dstack *st, int e)
{
    int i;
    if (istuefull(st))
    {
        printf("which side to inserte elemt.\n");
        scanf("%d", &i);
        if (i == 1)
        {
            st->top[1]  = st->top[1] - 1;
            st->data[st->top[1]] = e;
            return 1;
        }
        if (i==0)
        {
            st->top[0] = st->top[0] + 1;
            st->data[st->top[0]] = e;
            return 1;
        }
    }
    return 0;
}


int deStack(Dstack *st, int *p)
{
    int i;
    printf("which side element to delete\n");
    scanf("%d", &i);
    if ((i==1)&&(st->top[1]<maxSize))
    {
        *p = st->data[st->top[1]];
        st->top[1]++ ;
        return 1;
    }
    
    if ( (i == 0) && (st->top[0] >= 0))
    {
        *p = st->data[st->top[0]];
        st->top[0]--;
        return 1;
    }
    return 0;
}