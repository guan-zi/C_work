# include<stdio.h>
# include<string.h>
# include<stdlib.h>


int main()
{
	void delete_n(char str[], char del, int n);
	char str1[50];
	char ch;

	printf("input a string:\n");
	gets(str1);
	getchar(); //消除回车符
	printf("input a charater to delete:\n");
	scanf("%c", &ch);
	
	int s1_len = strlen(str1);
	delete_n(str1, chr, s1_len);
	printf("%s", str1);

	return 0;
}



void delete_n(char str[], char del, int n)
{
	int i=0, j;
	while(str[i])
	{
		if(str[i]==del)
		{
			for(j=i; j<n-1; j++)
				str[j]=str[j+1];
			n = n-1;
			str[n]=0;
		}
		else
			i++;
	}

}
