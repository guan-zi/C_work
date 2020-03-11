# include <stdio.h>
# include "studs_score.h"

int input_score(int array[], int n)
{
	int i=0;
	int x;
	int count=0;
	while(1)
	{
		printf("输入第%d个学生的成绩：",count+1);
		scanf("%d", &x);
		if (x>=0 && x<=100)
		{
			array[count] = x;
			count++;
		}
		else
			break;
	}
	return count;
}


void print_score(int array[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%d", array[i]);
		if((i+1)%5==0)
			printf("\n");
	}

}


int max_score(int score[], int n)
{
	int i;
	int max = score[0];
	for (i=1; i<n; i++)
	{
		if(max<score[i])
			max = score[i];
	}
	return max;
}


void exchange_sort(int array[], int n)
{
	int i,j;
	int temp;
	for(i=0; i<n-1; i++)
	{
		for(i=0; i<n-1; i++)
		{
			if(array[i]<array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}


void select_sort(int array[], int n)
{
	int i, j, k, t;
	for (i=0; i<n-1; i++)
	{
		k = i;
		for(j=i+1; j<n; j++)
			if(array[i]<array[k])
				k = j;
		if (k != i)
		{
			t = array[k];
			array[k] = array[i];
			array[i] = t;
		}
	}
}


int field_Score(int score[], int count, int field)
{
	int i=0;
	int nums=0;
	for(i=0; i<count; i++)
	{
		if(score[i]<field)
			nums++;
	}
	return nums;
}


int BinarySearch(int array[], int x)
{
	int low=0, high=N-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x==score[mid])
			return mid;
		else if (x<score[mid])
			high=mid-1;
		else
			low = mid+1;
	}
	return -1;
}
