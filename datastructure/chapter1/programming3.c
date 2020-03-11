#include <stdio.h>
#include <stdlib.h>
#define maxSize 100

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

void merge(LNode *A, LNode *B)
{
	LNode *pre,*p, *q,*s;
	pre = A;
	p = A->next;
	q = B->next;
	//free(B);
	while(p!=NULL&&q!=NULL)
	{
		if(p->data<q->data)
		{
			pre = p;
			p = p->next;
		}
		else
		{
		//	printf("%d%d",r->data,q->data);
			s = q;
		//	printf("%d%d",r->data,q->data);
			q = q->next;
		//	printf("%d%d",r->data,q->data);
			s->next = pre->next;
			pre->next = s;
			pre = s;
			//free(s);
		}
	}
	if(p->next == NULL)
		p->next = q;
	//return A;
}


int main()
{
	int c[5] = {1,3,5,6,8};
	int d[4] = {2,4,4,7};
	int i;
	LNode *A, *B, *p,*q;
	A = (LNode *)malloc(sizeof(LNode));
	A->next = NULL;
	p = A;
	for(i = 0; i<5; i++)
	{		
		q = (LNode *)malloc(sizeof(LNode));
		q->next = NULL;
		q->data = c[i];
		p->next = q;
		p = q;
	}

	p = A->next;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	
	B = (LNode *)malloc(sizeof(LNode));
	B->next = NULL;
	p = B;
	for(i = 0; i<4; i++)
	{		
		q = (LNode *)malloc(sizeof(LNode));
		q->next = NULL;
		q->data = d[i];
		p->next = q;
		p = q;
	}

	
/*	p = B->next;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
*/	
/*	p = B->next;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
*/	
	merge(A,B);
/*	q = B->next;
	while(q!=NULL)
	{
		printf("%d", q->data);
		q = q->next;
	}
	printf("\n");
*/
	p = A->next;
	while(p!=NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}
