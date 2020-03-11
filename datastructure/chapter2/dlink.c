#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef struct DLNode
{
    int data;
    struct DLNode *prior, *next;
}DLNode;


int initDLink(DLNode *dl)
{
    if (dl->next)
    {
        DLNode *p, *q;
        p = dl->next;
        while (p)
        {
            q = p->next;
            free(p);
            p = q;   
        }
        dl->next = NULL;
        return 1;
    }
    if (dl->next == NULL)
    {
        return 1;
    }
    return 0;
}


int createDLink(DLNode *dl)
{
    int lenght;
    time_t t;
    DLNode *p, *r;
    srand((unsigned)time(&t));
    printf("input the length of double link:\n");
    scanf("%d", &lenght);
    r = dl;
    while (lenght--)
    {
        p = (DLNode *)malloc(sizeof(DLNode));
        p->data = rand()%100;
        p->next = p->prior = NULL;
     /*   if (dl->next == NULL)
        {
            p->prior = dl;
            dl->next = p;
        }
        p->next = dl->next;
        dl->next->prior = p;
        p->prior = dl;
        dl->next = p;*/
        r->next = p;
        p->prior = r;
        r = p;
    }

    return 1;
}


int descending(DLNode *dl)
{
    DLNode *p, *pre, *s, *r;
    s = dl->next;
    dl->next = NULL;
    while(s)
    {
        r = s;
        s = s->next;
        r->next = NULL;
        r->prior = NULL;
        
        for( pre = dl, p = dl->next; p != NULL; )
        {
            // printf("the first round");
            if (r->data > p->data)
            {
                p->prior->next = r;
                r->prior = p->prior;
                r->next = p;
                p->prior = r;
                break;
            }
            pre = p;   
            p = p->next;
        }
        if (p ==NULL)
        {
            pre->next = r;
            r->prior = pre;
        }
    }
    return 1;
}
 

int insertDLink(DLNode *dl, int ps, int e)
{
    DLNode *p, *q;
    p = dl->next;

    q = (DLNode *)malloc(sizeof(DLNode));
    q->data = e;
    q->next= q->prior = NULL;
    int i;
    for ( i = 0; p->next!=NULL; i++)
    {
        if(ps == i)
        {
            q->next = p;
            q->prior = p->prior;
            p->prior->next = q;
            q->next = p;
            return 1;
        }
        p = p->next;
    }
    
    if ((p->next==NULL )&& (i==ps))
    {
        p->next = q;
        q->prior = p;
        return 1;
    }
    
    return 0;
}

int deleteElem(DLNode *dl, int e)
{
    DLNode * p;
    p = dl->next;
    while (p)
    {
        if (p->data == e)
        {
            if (p->next==NULL)
            {
                p->prior ->next = NULL;
                free(p);
                return 1;
            }
            
            p->prior->next = p->next;
            p->next->prior = p->prior;
            free(p);
            return 1;
        }
        p = p->next;
    }
    
    return 0;    
}

int mergeDLink(DLNode *dl1, DLNode *dl2, DLNode *dl3)
{
    DLNode *p, *q, *s, *r;
    p = dl1->next;
    q = dl2->next;
    r = dl3;
    // dl3->next = NULL;
    while (p&&q)
    {
        if (p->data > q->data)
        {
            s = p;
            p = p->next;
        }
        else
        {
            s = q;
            q = q->next;
        }
        s->next = r->next;
        r->next = s;
        s->prior = r;
        r = s;
    }
   while ((p == NULL)&& (q != NULL))
   {
       s = q;
       q = q->next;
        s->next = r->next;
        r->next = s;
        s->prior = r;
   }

   while ((q == NULL)&& (p != NULL))
   {
       s = p;
       p = p->next;
        s->next = r->next;
        r->next = s;
        s->prior = r;
   } 
   return 1;
}


int main()
{
    DLNode *l1, *l2, *l3, *p;
    printf("create a double link\n");
    l1 = (DLNode *)malloc(sizeof(DLNode));
    l1->next = l1->prior = NULL;
    
    l2 = (DLNode *)malloc(sizeof(DLNode));
    l2->next = l2->prior = NULL;

    l3 = (DLNode *)malloc(sizeof(DLNode));
    l3->next = l3->prior = NULL;
    createDLink(l1);
    createDLink(l2);
    p = l1->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");
    
    p = l2->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");

    printf("insert an value in link l2\n");
    insertDLink(l2, 3, 50);
    printf("delete an element of l1\n");
    int e;
    scanf("%d", &e);
    deleteElem(l1, e);
    printf("\n");
    p = l1->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");
    
    p = l2->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");

    descending(l1);
    descending(l2);
 p = l1->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");
    
    p = l2->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");

    mergeDLink(l1,l2, l3);
    
    p = l3->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");
    initDLink(l3);p = l3->next;
    while (p)
    {
        printf("%d\t", p->data);
        p  = p->next;
    }
    printf("\n");


    return 1;
}