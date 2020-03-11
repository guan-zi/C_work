# include <stdio.h>
# include<string.h>

#define N 30


int main()
{
	char str[N];
	int i=0, inum=0;
	printf("input a string:");
	gets(str);
	while(str[i])
	{
		if(str[i]>='0'&&str[i]<='9')
			inum++;
		i++;
	}
	printf("string %s include %d numbers", str,inum);
	return 0;
}

