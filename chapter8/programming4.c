#include <stdio.h>
#include <stdlib.h>


typedef struct MONKEY
{
	int mnum;
	struct MONKEY *next;
}MONKEY;


int main()
{
	int m, n;
	printf("input monkey number m:\n");
	scanf("%d", &m);
	printf("input alart number n:\n");
	scanf("%d", &n);
	MONKEY *head = (MONKEY *)malloc(sizeof(MONKEY));
	head->next = head;
	head->mnum = 1;
	
	int i,count=0, counter=1;
	MONKEY *p;
	for(i = m;i>1;i--)
	{
		p = (MONKEY *)malloc(sizeof(MONKEY));
		p->mnum = i;
		p->next = head->next;
		head->next = p;
		
		counter++;
	}
	printf("create monkey circle\n");
	
	for (p = head,count=1; counter>1; )
	{
	
		if(count==n)
		{
			printf("delet monkey %d\n",p->mnum);
			p->mnum = p->next->mnum;
			p->next = p->next->next;
			counter--;
			count = 1;
		}
		
		count++;
		p = p->next;
	}
	printf("monkey king is %d\n",p->mnum);
	return 0;

}
