# include<stdio.h>
# include "programming1.h"

int main()
{
	float std_score[MAXNUMS][5]={0.0};
	int i,j,c,s,k ,n;
	n = getScore(std_score);
	averageTotalScore(std_score, n);
	individualAverageTotal(std_score, n);

	while(TRUE)
	{
		printf("select categroy:\n\tsingal subject average score:0\n\tsingal subject total score:1\n\tindividual score:2\n\tprint all students score:3\n\tquit:4\n");
		scanf("%d", &c);
		if(c!=4)
			switch(c)
			{
				case 0: 
				{	
					printf("Which subject average score:\n\t数学：0\n\t语文：1\n\t英语：2\n");
					scanf("%d", &i);
					printf("%f\n",std_score[n][i]);
					break;
				}
				case 1:
				{	
					printf("Which subject total score:\n\t数学：0\n\t语文：1\n\t英语：2\n");
					scanf("%d", &j);
					printf("%f\n",std_score[n+1][i]);
					break;
				}
				case 2:
				{	
					printf("which student %d", s);
					scanf("%d", &s);
					printf("Which subject total score:\n\t数学：0\n\t语文：1\n\t英语：2\n\taverage score:3\n\ttotal score:4\n");

					scanf("%d", &k);
					printf("%f\n", std_score[s][k]);
					break;
				}
				case 3: printScore(std_score, n);break;
			}
		else break;
	}
	return 0;
}
