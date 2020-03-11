# include<stdio.h>


int oddoreven(int x){
	if(x!=0)
	{
		if(x/2==0)
			return 0;
		else
			return 1;
	}
}


int main(){
	int i,j;
	printf("input an int number:\n");
	scanf("%d", &i);
	j = oddoreven(i);
	if(j)
		printf("%d is even",i);
	else
		printf("%d is odd",i);

	return 0;


}
