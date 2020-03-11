# include<stdio.h>


int fun(int a){
	int mul, i;
	if (a==1)
		return 1;
	else
		for (mul=1,i=1; i<a*2; i++)
			mul *=i;
		return fun(a-1)+mul;

}


int main(){
	int a;
	printf("input a:\n");
	scanf("%d", &a);
	printf("sum is %d", fun(a));
	return 0;
}
