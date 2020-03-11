#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;


int createLink(LNode *L)
{   int i;
    LNode *p, *q, *head;
    p = L;
    for ( i = 0; i < 5; i++)
    {
        q = (LNode *)malloc(sizeof(LNode));
        if(q)
        {
            q ->next = p->next;
            q->data = i;
            p->next = q;
            p = p->next;
        }
    }
    // L = head;
    return 1;
}


 int ascending(LNode *L)
{
    LNode *p, *pre, *r, *s;
    s = L->next;  //s指向第一个元素
    L->next = L;  //L变为空
    while (s!=L)
    {
        r = s;
        s = s->next;
        r->next = NULL;
        for ( pre = L, p= L->next; p != L;)
        {
            if(r->data<p->data)
            {
                pre->next = r;
                r->next = p;
                break;
            }
            pre = p;
            p = p->next;
        }
        if (p ==  L) //当链表为空或者所有的节点值都小于心结点
        {
            pre->next = r;
             r->next = p;

        }
    }

    pre->next = L;
    return 1;
}


int main()
{
    LNode *L,*p;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = L;
    createLink(L);
    p = L->next;
    while(p !=L)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    ascending(L);

    p = L->next;
    while(p !=L)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    return 1;
}