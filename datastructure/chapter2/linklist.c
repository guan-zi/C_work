#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
typedef struct LNode
{
    int data;
    struct LNode *next;   
}LNode;


int initLink(LNode *L)
{
    LNode *head=L->next, *p;
   while (head)
   {
       p  = head;
       head = head->next;
       free(p);
   }
    L->next = NULL;
    printf("initiate success.\n");
   return 1;
}


int insertElem(LNode *L, int ps, int e)
{
    if(L->next  != NULL)
    {
        int i, count = 0;
        LNode *pre, *p, *s;
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = NULL;
        for(pre = L, p = L->next; p!=NULL; pre = p, p = p->next)
            if(count++ == ps)
            {
                s->next = p;
                pre->next = s;
                // free(s);  // 此处释放内存导致，插入值被释放，得不到被插入值。
                return 1;
            }
    }
    return 0;
}


int deleteElem(LNode *L, int ps,int *e)
{
    if (L->next != NULL)
    {
        int i, count = 0;
        LNode *p, *pre;
        for(pre = L, p = L->next; p!=NULL;pre = p, p= p->next)
        {
            if (count++ == ps )
            {
                *e = p->data;
                pre->next = p->next;
                return 1;
            }
        }
        if (count -1<ps)
        {
            printf("length of the link is %d shorter than your expect\n", count);
            return 0;
        }
        
    }
     
    return 0;
}

int createLink(LNode *L)
{
    int i, mathod, length;
    LNode *head = L;
    LNode  *p;
    printf("input mathod to create link(0:for random/1:manual input):\n");
    scanf("%d", &mathod);
    printf("input lenght of the link:\n");
    scanf("%d", &length);

    if (mathod == 0)
    {
        time_t t;
        if (head)
        {
            srand((unsigned)time(&t));
            for ( i = 0; i < length; i++)
            {
                p = (LNode *)malloc(sizeof(LNode));
                p->data = rand()%100;
                p ->next = head->next;
                head->next = p;
            }
            // L = head;
            return 1;
        }
    }

    if (mathod == 1)
    {
        if (head)
        {
            // head->next = NULL;
            LNode *q = L;
            int data;
            for(i = 0; i<length; i++)
            {
                p = (LNode *)malloc(sizeof(LNode));
                p->next =NULL;
                printf("Please input the %d element:\n ", i);
                scanf("%d", &data);
                p->data = data;
                q ->next =p;
                q = q->next;
            }
            
            // L = head;
            return 1;
        }
    }
    
}

int mergeLink(LNode *La, LNode *Lb, LNode *Lc)
{
    int i;
    LNode *p, *q, *r;
    // free(Lc);
    // Lc = La;
    // r = Lc;
    p = La->next;
    r = Lc;
    r->next = NULL;
    q = Lb->next;
    while ((p!=NULL)&&(q!=NULL))
    {
        if(p->data < q->data)
        {
            r->next = p;
            p = p->next;
            // r = r->next;
            // r->next = NULL;
        }
        else
        {
            r->next = q;
            q = q->next;
            // r = r->next;
            // r->next = NULL;
        }
        
        r= r->next;
        // printf("%d\t", r->data);
        r->next = NULL;
    }

    if (p !=NULL)
    {
        r->next = p;
        // printf("%d",  r->next->data);
    }
    else
    {
        r->next = q;
        // printf("%d",  r->next->data);
    }
   return 1;
}


int ascending(LNode *L)
{
    if(L->next)
    {
        LNode  *head, *p, *s, *pre;
        head = L-> next;
        L->next = NULL;
        for (; head != NULL; )
        {
            s = head;
            head = head->next;
            s->next = NULL;
            // printf("%d\t", s->data);
            for ( pre = L, p = L->next; p !=NULL;)
            {
                if (s->data < p->data) //结点插入位置总是在pre后面,符合插入条件则插入，否则执行选择语句外面的语句
                {
                    pre->next = s;
                    pre = pre->next;
                    pre->next = p;
                    break;
                }
                pre = p;   //如果没有跳出，则总是执行指针的向后移动;
                p = p->next;
            }

           if (p == NULL)
           {
               pre->next = s;
               p = s;
           }
        }
        return 1;
    }
    return 0;
}

int main()
{
    int ln, de, *elem=&de;
    LNode *L1,*L2, *L3=NULL, *p;
    int result;
    // result = initLink(L);
    // printf("%d",result);
//    printf("\n") ;
    L1 = (LNode *)malloc(sizeof(LNode));
    L1->next = NULL;
/*    if (!L)
    {
        printf("apply memory failed");
        return 0;
    }
  */  
    L2 = (LNode *)malloc(sizeof(LNode));
    L2->next = NULL;
    createLink(L1);
    createLink(L2);

    L3 = (LNode *)malloc(sizeof(LNode));
    L3->next = NULL;
   
    p = L1->next;
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    // initLink(L);
    // ascending(L);

    p = L2->next;
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
  /*  insertElem(L, 3, 10);
    p = L->next;
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

    deleteElem(L, 6, elem);
*/
    ascending(L1);
    ascending(L2);

    p = L1->next;
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    p = L2->next;
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    mergeLink(L1, L2, L3);
    p = L3->next;
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 1;    
}