#include <stdio.h>
#include <math.h>

int x = 57;

int isprime(int n){
	int i;
	if(n==1||n==2)
		return 1;
	else
	{	
		for(i = ceil(sqrt(n)); i>1; i--)
		{
			if (n%i==0)
				return 0;
		}
	}

	return 1;

}


int main(void){
	int i;
	i = isprime(x);
	if(i==0)
		printf("x is NOT prime");
	else
		printf("x is prime");

	return 0;
}

