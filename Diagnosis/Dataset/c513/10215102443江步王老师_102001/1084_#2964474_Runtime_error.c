#include<stdio.h>

long long count(int n);

int main()
{
    int t;
    int i;
    long long res;
    scanf("%d",&t);
    for (i=0;i<t;i++)
    {
        int n;
        scanf("%d",n);
        printf("case #%d:\n",i);
        res=count(n);
        printf("%lld\n",res);
    }
}

long long count (int n)
{
    
    if (!n)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
    else
    {
        return count(n/2)*count(n-n/2);
    }
}