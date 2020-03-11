#include <stdio.h>
void writestr(char *fn, char *str)
{
    FILE *fp;
    fp = fopen(fn, "a");
    fputs(str, fp);
    fclose(fp);
};

int main()
{
    writestr("t1.txt", "start");
    writestr("t1.txt", "end");
    return 0;
}