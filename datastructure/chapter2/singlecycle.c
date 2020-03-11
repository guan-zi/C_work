#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

int initSLink(LNode *L)
{
    LNode *r;
    if (L->next != L)
    {
        while (1)
        {
            r = L->next;
            L->next = r->next;
            if(L->next  == L)
                return 1;
            free(r); 
        }
    }  
      
}


int createSLink(LNode *L)
{
    time_t t;
    int length;
    LNode *s;
    srand((unsigned)time(&t));
    printf("input the length of single link.\n");
    scanf("%d", &length);
    while (length--)
    {
        if((s = (LNode *)malloc(sizeof(LNode)))==NULL);
        {
            s->next = NULL;
            s->data = rand()%100;
            s->next =  L->next;
            L->next = s;
        }
    }
    return 1;
}

int deleteElem(LNode *L, int e)
{
    LNode *p, *pre;
    pre = L;
    p = L->next;
    while (p != L)
    {
        if(p->data == e)
        {
            pre->next = p->next;
            free(p);
            return 1;
        }
        pre = p;
        p = p->next;
    }
    return 0;
}


int insertElem(LNode *L, int ps, int e)
{
    LNode *p, *pre, *s;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    pre = L;
    p = L->next;
    while(1)
    {

        ps--;
        if (ps == 0)
        {
            pre->next = s;
            s->next = p;
            return 1;
        }
        pre = p;
        p = p->next;

    }
    return 0;
}

int merge(LNode *L1, LNode * L2, LNode *L3)
{
    LNode *p, *q, *s, *r;
    p = L1->next;
    q = L2->next;
    r = L3;
    while((p!= L1)&&(q!=L2))
    {
        if (p->data > q->data)
        {
            s = q;
            q = q->next;
        }
        else
        {
            s = p;
            p = p->next;
        }
        r->next = s;
        r = r->next;
        r ->next = NULL;
    }

    while ((p == L1)&&( q!= L2))
    {
        s = q;
        q = q->next;
        r->next = s;
        r = r->next;
    }

    while ((q == L2)&&( p!= L1))
    {
        s = p;
        p = p->next;
        r->next =s;
        r = r->next;
    }
    r ->next = L3;
    return 1;    
}

int ascending(LNode *L)
{
    LNode *p, *pre, *r, *s;
    s = L->next;  //s指向第一个元素
    // L->next = L;  //L变为空
    while (s!=L)
    {
        r = s;
        s = s->next;
        r->next = NULL;
        for ( pre = L, p= L->next; p != NULL;)
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
        if (p ==  NULL) //当链表为空或者所有的节点值都小于心结点
        {
            pre->next = r;
             r->next = p;
        }
    }

    for (pre = L, p = L->next; p!=NULL; )
    {
        // printf("%d\t", p->data);
        pre = p;
        p = p->next;
    }
    // printf("\n");
    pre->next = L;
    return 1;
}

int main()
{
    int ps, e;
    LNode *L1, *L2, *L3;
    LNode *p;
    L1 = (LNode *)malloc(sizeof(LNode));
    L1->next = L1;

    L2 = (LNode *)malloc(sizeof(LNode));
    L2->next = L2;

    L3 = (LNode *)malloc(sizeof(LNode));
    L3->next = L3;
    
    createSLink(L1);
    createSLink(L2);
    
    p = L1->next;
    while (p!=L1)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("L1 \n");
    p = L2->next;
    while (p!=L2)
    {
        printf("%d\t", p->data);
        p = p->next;
    }

  printf("L2 \n");
    insertElem(L1, 4, 35);
    printf("insert succeed\n");
    p = L1->next;
    while (p!=L1)
    {
        printf("%d\t", p->data);
        p = p->next;
    }

    printf("\n");
    printf("input the element in L2 you want to delete.\n");
    scanf("%d", &e);
    deleteElem(L2, e);

    p = L2->next;
    while (p!=L2)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

    ascending(L1);
    ascending(L2);

    printf("L1 ascending complete\n");
    p = L1->next;
    while (p!=L1)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    
    printf("L2 ascending complete\n");
    p = L2->next;
    while (p!=L2)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

    merge(L1, L2, L3);
    p = L3->next;
    while (p!=L3)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("merge succeed\n");

    return 1;
}