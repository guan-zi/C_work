# include<stdio.h>


int fun(){
	int count=0;
	int i;
	for(i=1; i<200; i++)
	{	if((i%3==0)&&(i%10==6))
		{
			count++;
			printf("%d\t",i);
		}
	}
	return count;
}

int main(){
	int i;
	i=fun();
	printf("total %d under 200\n", i);
	return 0;
}
