#include<stdio.h>

unsigned long long f(int n)
{
    if(n ==0)
    {
        return 1;
    }
    else if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else if(n == 3)
    {
        return 4;
    }
    else
    {
        int a = 1, b = 1, c = 2, d = 4, end;
        for(int j = 3; j < n; j++)
        {
            end = a + b + c +d;
            a = b;
            b = c;
            c = d;
            d = end;
        }
        return end;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        long long m = f(n);
        printf("%lld\n",m);
    }
    return 0;
}

