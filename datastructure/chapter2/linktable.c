#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define maxSize 100

typedef struct
{
    int data[maxSize];
    int  length;
}Sqlist;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;


typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

void createList(Sqlist *L,int n)
{
    int i, m=n;
    time_t t;

    srand((unsigned)time(&t));
    // printf("%d", rand()%100);
    printf("\n");

    for ( i = 0; i < m ; i++)
    {
        L->data[i] = rand()%100;
        // printf("%d\t", L->data[i]);
    }    
    // printf("\n");
    L->length = n;

    
}

int findelem(Sqlist *L, int e)
{
    int i;
    for(i = 0; i < L->length; i++)
        if (e == L->data[i])
            return i;
    return -1;
}

int insertElem(Sqlist  *L, int p, int e)
{
    int i;
    if (p<0 || p > L->length-1 || L->length>maxSize)
    {
       return 0; 
    }
    for(i = L->length; i>=p; i--)
    {
        L->data[i] = L->data[i-1];
    }
   L->data[i+1] = e;
   L->length++;
   return 1;  
}   


int deleteElem(Sqlist *l, int p, int *e)
{
    int i, j;
    /*for ( i = 0; i < l->length; i++)
    {
        if (l->data[i] == e)
        {
            for ( j = i; j <l->length-1 ; j++)
            {
                l->data[j] = l->data[j+1];
            }
            l->length--;
        }
        
    }*/      //删除顺序表中值为e的所有元素;
    if (p<0 || p>l->length-1)
    {
        return 0;/* code */
    }
    * e = l->data[p];
    for ( i = p; i <l->length-1; i++)
    {
        l->data[i] = l->data[i+1];
    }
    l->length--;
        return 1;
}


void initList(Sqlist *l)
{
    l->length = 0;
}

int getElem(Sqlist *l, int p, int *e)
{
    if (p<0||p>l->length-1)
    {
        return 0;/* code */
    }
    
    *e = l->data[p];
    return 1;
}



int main()
{
    // time_t t;
    int i, n;
    Sqlist *L = NULL ;
    // int (*func[6]) (Sqlist, int) //函数指针必须所有函数必须有同样的参数
    L = (Sqlist *)malloc(sizeof(Sqlist));
    // t = time();
    printf("Enter the length of sequeue list:\n");    
    scanf("%d", &n);
    createList(L,n );
    // time_t t;
    // srand((unsigned)(time(&t)));
    // for ( i = 0; i < n; i++)
    // {
    //     L.data[i] = rand()%100;
    // }
    // L.length = n;

    for ( i = 0; i < n; i++)
    {
        printf("%d\t", L->data[i]);
    }
    printf("\n");
    printf("%d",n);
    // printf("choose operation :\n");
    int *p, e;
   scanf("%d", p);
   deleteElem(L,e, p);
   printf("\n");
//    printf("%d", *p);
   insertElem(L, 8, 9);
   insertElem(L, 8, 9);
   insertElem(L, 8, 9);
   insertElem(L, 8, 9);
    
    for ( i = 0; i < L->length; i++)
    {
        printf("%d\t", L->data[i]);
    }
    printf("\n");
    return 1;
}