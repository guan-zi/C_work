# include<stdio.h>
# include"programming_8.h"

int main(){
	int n;
	printf("input a number:\n");
	scanf("%d", &n);
	if(fun(n))
		printf("yes\n");
	else
		printf("no\n");
	return 0;

}

