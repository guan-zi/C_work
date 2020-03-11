# include<stdio.h>
# include<math.h>


float fun1(float a){
	return a*a*a;
}

float fun2(float b){
	return fabs(b);
}


int main(){
	float i, res;
	printf("int a number:\n");
	scanf("%f", &i);
	res = fun1(i);
	printf("result is %f\n",fun2(res));
	return 0;
	
}
