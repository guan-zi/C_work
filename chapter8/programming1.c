#include <stdio.h>

struct{
	int num;
	float emid;
	float efinal;

}stu;

int main()
{
	float escore;
	scanf("%d,%f,%f", &stu.num, &stu.emid, &stu.efinal);
	escore = stu.emid*0.3 + stu.efinal*0.7;

	printf("%f",escore);
	return 0;
}
