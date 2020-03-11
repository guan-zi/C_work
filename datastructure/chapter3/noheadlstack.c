# include <stdio.h>
#include <malloc.h>


typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

int initStack(LNode *ls)
{
    ls = NULL;
    return 1;
}


int isEmpty(LNode *ls)
{
    if (ls==NULL)
    {
        return 1;
    }
    return 0;
}


int push(LNode *ls, int e)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    p->next = NULL;
/*    if (ls==NULL)
    {
        ls = p;
        return 1;
    }
    else
    {
        p->next = ls;
        ls = p;
        return 1;
    }
    return 0;
    */
   p->next = ls;
   ls = p;
   return 1;
}

int pop(LNode *ls, int *p)
{
    if (!isEmpty(ls))
    {
        printf("stack is empty\n");
        return 0;
    }
    LNode *q;
    q = ls;
    *p = q->data;
    ls = ls->next;
    free(q);
    return 1;
}