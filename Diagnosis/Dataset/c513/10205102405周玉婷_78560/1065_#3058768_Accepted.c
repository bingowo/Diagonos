#include <stdio.h>
int times = 0;
int up1(int a, int n)
{
    if(n == 1) return a;
    if(n == 2) {times++; return 0;}
    return up1(a, n-1) + up1(a, n-2);
}
int up_x(int a, int p, int x)
{
    if(x == 1) return a;
    if(x == 2) return p;
    return up_x(a,p, x-1) + up_x(a, p,x-2);
}

int main()
{
    int a, n, m, x;
    scanf("%d %d %d %d", &a, &n, &m, &x);
    int p = (m -a - up1(a, n-1))/(times-1);
    int res;
    if(x > 1)  res = up_x(a, p, x) + a - p;
    else  res = a;
    printf("%d\n", res);
    return 0;
}