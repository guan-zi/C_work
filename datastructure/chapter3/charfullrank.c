

void param(char str[], int k, int n)
{
    int i, j;
    char temp;
    if (k==0)
    {
        for ( j = 0; j < n; j++)
        {
            printf("%c\t", str[j]);
        }
    }
    else
    {
        for ( i = 0; i <= k; i++)
        {
            temp = str[i];
            str[i] = str [k];
            str[k] = temp;
            param(str, k-1, n);

            temp = str[i];
            str[i] = str [k];
            str[k] = temp;
        }
        
    }
    
        
}