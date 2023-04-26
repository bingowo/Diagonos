#include <stdio.h>
#include <stdlib.h>

long long num[50];
long long cnt(int n)
{
    num[0]=1;
    num[1]=1;
    num[2]=2;
    num[3]=4;
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    else if(n==3)
    {
        return 4;
    }
    else
    {
        for(int i=4;i<=n;i++)
        {
            num[i]=num[i-1]+num[i-2]+num[i-3]+num[i-4];
        }
        return num[n];
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",cnt(n));
    }
    return 0;
}

