#include <time.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

typedef struct LQueue
{
    LNode *front;
    LNode *rear;
}LQueue;


int initLq(LQueue *lq)
{
    lq->front = lq->rear = NULL;
    return 1;
}

int isEmpty(LQueue *lq)
{
    if (lq->rear == NULL || lq->front== NULL)
    {
        return 1;
    }
    return 0;
}


int enque(LQueue *lq, int e)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    p->next = NULL;
    if (isEmpty(lq))
    {
        lq->front = p;
        lq->rear = p;
    }
    else
    {
        lq->rear->next = p;
        lq->rear = p;
    }
    
   return 1;
}

int deque(LQueue *lq, int *p)
{
    if (isEmpty(lq))
    {
        return 0;
    }
    LNode *q;
    q = lq->front;
    if (lq->front == lq->rear)
    {
       lq->front = lq->rear = NULL; 
    }
    else
    {
        lq->front = lq->front->next;
    }
    *p = q->data;
    free(q);
    return 1;
}


int main()
{
    LQueue *L;
    LNode *p;
    int i;
    time_t t;
    srand((unsigned)time(&t));
    initLq(L);

    L = (LQueue *)malloc(sizeof(LQueue));
    initLq(L);

    for ( i = 0; i < 10; i++)
    {
        enque(L, rand()%100);
    }

    p = L->front;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");

    // deque()
    return 1;
}
