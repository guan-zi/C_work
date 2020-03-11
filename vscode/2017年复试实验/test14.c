#include <stdio.h>

int main()
{
    FILE *fp;
    int a[10] = {1, 2, 3}, i, n;
    fp = fopen("d1.dat", "w");
    for ( i = 0; i < 3; i++)
    {
        fprintf(fp, "%d", a[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
    fp = fopen("d1.dat", "r");
    fscanf(fp, "%d", &n);
    printf("%d\n", n);
    return 1;
}
