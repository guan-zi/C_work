# include <stdio.h>
struct s{
    int x, y;
}data[2] = {10, 100, 20, 200};

int main()
{
    struct s *p=data;
    printf("%d", ++(p->x));
    return 0;
}