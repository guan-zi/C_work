#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

int initLStack(LNode *LS)
{
    if (LS->next != NULL)
    {
        LNode *p;
        while(LS->next)
        {
            p = LS->next;
            LS->next = p->next;
            free(p);
        }
    }
    return 1;   
}

int pushStack(LNode *LS, int e)
{
    LNode *p;
    if((p = (LNode *)malloc(sizeof(LNode)))==NULL)
    {
        p ->next = NULL;
        p->data = e;
        p->next = LS->next;
        LS->next = p;
        return 1;
    }
    return 0;
}


int popLStack(LNode *LS, int *p)
{
    if (LS->next)
    {
        LNode *q;
        q = LS->next;
        *p = LS->next->data;
        LS->next = LS->next->next;
        free(q);
        return 1;
    }
    return 0;
}

int isEmpty(LNode *LS)
{
    if (LS->next == NULL)
    {
        return 1;
    }
    return 0;
    
}

