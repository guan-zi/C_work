# include<stdio.h>

int getScore(float std_score[][5])
{
	int i,j,n;
	printf("input number of students:\n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("please input student %d score math Chinese English\n", i);
		for(j=0; j<3; j++)
			scanf("%f",&std_score[i][j]);
			getchar();
	}
	return n;
}


int averageTotalScore(float std_score[][5], int n)
{
	int i, j;
	float sum;
	for(i=0; i<3; i++)	
	{
		sum = 0.0;
		for(j=0; j<n; j++)
			sum +=std_score[j][i];
		std_score[n][i]=sum/n;
		std_score[n+1][i] = sum;
	}
	return 0;
}


/*int totalScore(float std_score[][5], int n)
{
	int i,j;
	float total[3];
	float ave;
	for(j=0; j<3; j++)
	{
		ave = averageScore(std_score[][i], int n);
		std_score[n+1][j] = ave*n;
		printf("subject %d total score:%f\n", j, std_score[n+1][j]));
	}
	return 0;
}
*/

int individualAverageTotal(float std_score[][5], int n)
{
	int i,j;
	float sum;
	for(i=0;i<n;i++)
	{
		sum = 0.0;
		for(j=0; j<3;j++)
			sum +=std_score[i][j];
		std_score[i][4] = sum;
		std_score[i][3] = sum/3;
		printf("student %d average score:%f\n", i, std_score[i][3]);
	}

	return 0;
}


void printScore(float std_score[][5], int n)
{
	int i, j;
	printf("number\tmath\tchinese\tEnglish\taverage\ttotal\n");
	for(i=0;i<n+2;i++)
	{
		printf("%d\t",i);
		for(j=1;j<5;j++)
			printf("%f\t", std_score[i][j]);
		printf("\n");
	}
}
