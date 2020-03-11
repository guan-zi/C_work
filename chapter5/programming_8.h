# include<stdio.h>

int fun(int x)
{
	int a[10], i=0,n=0;
	while(x){
		a[i++] = x%10;
		x = x/10;
		n++;
	}
	for(i=0; i<n/2;i++)
		if(a[i]!=a[n-i-1])
			return 0;
	return 1;

}


/*int main(){
	int n;
	printf("input a number:\n");
	scanf("%d", &n);
	if(fun(n))
		printf("yes\n");
	else
		printf("no\n");
	return 0;

}
*/
