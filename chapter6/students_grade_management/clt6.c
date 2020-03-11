# include<stdio.h>
# include "studs_score.h"


int main()
{
	int score[NUMS]={0};
	int count=0;
	int max;
	count = input_score(score, NUMS);
	print_score(score, count);
	max = max_score(score, count);
	select_sort(score, count);
	printf("最高分：%d\n", max);
	return 0;
}
