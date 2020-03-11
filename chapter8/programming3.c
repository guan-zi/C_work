#include <stdio.h>
#define N 5

struct result
{
	char name[20];
	float score[6];
	float aver;
};

void average(struct result player[N], int n)
{
	int i, j, min, max;
	float sum;
	for (i=0; i<n; i++)
	{
		sum=0.0;
		min = 0;
		max = 0;
		printf("%f,%f,%f,%f,%f,%f\n",player[i].score[0],player[i].score[1],player[i].score[2],player[i].score[3],player[i].score[3],player[i].score[4]);
		for(j=0; j<6; j++)
		{
			if(player[i].score[j] > player[i].score[max])
				max = j;

			if(player[i].score[j] < player[i].score[min])
				min = j;
		}
		for(j=0; j<6; j++)
		{	
				
				sum += player[i].score[j];
			
		}
		printf("%d,%d,%f\n", min, max, sum);
		player[i].aver = (sum-player[i].score[max]-player[i].score[min])/4;
	}
}


void getscore(struct result player[N], int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{	
		printf("input player %d score,seperate with \',\':\n", i);
		scanf("%f,%f,%f,%f,%f,%f",&player[i].score[0],&player[i].score[1],&player[i].score[2],&player[i].score[3],&player[i].score[4],&player[i].score[5]);

	}
}



int main()
{
	struct result player[N];
	//float aver[N] = 0.0;
	int i;

	getscore(player, N);

	average(player, N);

	for(i=0; i<N; i++)
		printf("player%daverage score %f\n",i, player[i].aver);

}
