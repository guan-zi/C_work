# include <stdio.h>
#define maxSize 100

typedef struct SQueue
{
    int data[maxSize];
    int front, rear;
}SQueue;


int initsqueue(SQueue *sq)
{
    sq->front = sq->rear = 0;
    return 1;
}

int issqEmpty(SQueue *sq)
{
    if (sq->front == sq->rear)
    {
        return 1;   /* code */
    }
    return 0;
}

int enQueue(SQueue *sq, int e)
{
    if((sq->rear+1)%maxSize== sq->front)
    {
        printf("queue is full\n");
        return 0;
    }
    sq->rear = (sq->rear+1)%maxSize;
    sq->data[sq->rear] = e;
    return 1;
}

int issqFull(SQueue *sq)
{
    if ((sq->rear+1)%maxSize== sq->front)
    {
        return 1;
    }
    return 0;
}

int dequeue(SQueue *sq, int *p)
{
    if (issqEmpty(sq))
    {
        return 0;
    }
    sq->front = (sq->front+1)%maxSize;
    *p = sq->data[sq->front];    
    return 1;
}