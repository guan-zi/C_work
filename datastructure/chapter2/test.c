# include <stdio.h>
#include <stdlib.h>
#define N 5

//      void fun(char str[])
//     {
//        printf("After transform:%d\n", sizeof(str));
//     }

//     int main(){ 
// 	char strs[]="abcdefg"; 
// 	printf("Before transform:%d\n",sizeof(strs));
// 	fun(strs);
// 	return 0;
// }


// 
void Insert(int *p, int n, int x){
	int i, pos;
	for ( i = 0; (i < n)&&(x > *(p+i)); i++)
		;
	pos = i;
	for ( i = n; i > pos ; i--)
	{
		*(p+i) = *(p+i-1); 
	}
	p[pos] = x;
	
}
int main()
{
	int a[N+1], i, j;
	printf("Please enter array a:\n");
	for ( i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Sorting ......:\n");
	
	for ( i = 0; i < N; i++)
	{
		printf("After insert %d:\n", a[i]);
		Insert(a, i, a[i]);
		for ( j = 0; j < N; j++)
		{
			printf("%-4d", a[j]);
		}
			// system("pause\n");
		printf("press any key continue......");
		getchar();
	}
}