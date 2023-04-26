#include <stdio.h>

int laber(int s, int a)
{
    if (s == 0) return 0;
    return 4*a + laber(s - a*a, a);
}
int find(int x, int y)
{
    int i;
    for (i = y;((x % i != 0) || (y % i != 0)) && i != 1;i--);
    return i;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", laber(x*y, find(x, y)));
    return 0;
}