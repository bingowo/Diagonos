#include <stdio.h>

int laber(int s, int a)  return 4*a + laber(s - a*a, a);
int find(int x, int y)
{
    for (i = y;(x % i != 0 && y % i != 0) || i != 1;i--);
    return i;
}
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%lf", laber(x*y, find(x, y)));
    return 0;
}