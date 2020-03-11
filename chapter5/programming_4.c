# include<stdio.h>
# include<math.h>


float fun(float a, float b){
	return fabs(a-b);//return (a>b)?(a-b):(b-a);
}

int main(){
	float a;
	float b;
	printf("input number a:\n");
	scanf("%f", &a);
	printf("input number b:\n");
	scanf("%f", &b);
	
	printf("abs is %f\n",fun(a,b));
	return 0;

}
