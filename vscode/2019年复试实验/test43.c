#include <stdio.h>

int pellArray(int k)
{
    if (k==1)
    {
       return 1;
    }
    else if (k == 2)
    {
        return 2;
    }
    else
    {
        return 2*pellArray(k-1)+pellArray(k-2);
    }
}


int main()
{
    int k;
    int value;
    printf("input the value of k:\n");
    scanf("%d", &k);
    value = pellArray(k);
    printf("%d",(value%32767));
    return 1;
}