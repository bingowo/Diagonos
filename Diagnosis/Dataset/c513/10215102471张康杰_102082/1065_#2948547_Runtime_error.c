#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
        return f(n - 1) + f(n - 2);
}

int f1(int x, int first, int second)
{
    if(x == 1)
        return first;
    else if(x == 2)
        return second;
    else
        return f1(x - 2, first, second);
}

int main()
{
    int a,n,m,x;
    scanf("%d %d %d %d",&a,&n,&m,&x);
    int*station, i, sum1 = 0, sum2 = 0, a2;
    station = (int*)malloc(n*sizeof(n));
    station[0] = a,station[1] = 1,station[n - 1] = 0;
    for(i = 1;i <= n - 3;i++)
    {
        sum1 += f(i);
    }
    sum1 = a*sum1 + a;
    for(i = 1;i <= n - n - 2;i++)
    {
        sum2 += f(i);
    }
    a2 = (m - sum1) / sum2;
    printf("%d\n",f1(x, a, a2));

}