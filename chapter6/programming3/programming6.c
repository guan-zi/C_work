# include<stdio.h>
# include<string.h>


int main()
{
	char str[]="computer";
	int i=0;
	while(str[i]&&i<strlen(str))
	{
		printf("%c", str[i]);
		i += 2;
	}
	printf("\n");
	return 0;
}
