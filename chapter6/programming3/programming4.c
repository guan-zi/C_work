# include<stdio.h>
# include<string.h>


int main()
{
	char s1[50], s2[20];
	printf("input two string:\n");
	scanf("%s%s",s1,s2);
	int n;
	printf("input insert position:\n");
	scanf("%d", &n);
	int i, j;
	int s2_len;
	s2_len = strlen(s2);
	s1[strlen(s1)+s2_len] = '\0';
	for(i=strlen(s1)-1; i>=n; i--)
		s1[i+s2_len]=s1[i];

	for(j=0;j<s2_len;j++)
		s1[n+j]=s2[j];

	printf("%s,%s",s1,s2);
	return 0;
}
