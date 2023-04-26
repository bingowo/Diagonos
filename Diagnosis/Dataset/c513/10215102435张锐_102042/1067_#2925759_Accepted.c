#include <stdio.h>
#include <stdlib.h>
long long int ans(int x)
{
    if(x==0) return 0;
    if(x==1||x==2) return 1;
    long long int x1=0,x2=1,x3=1;
    for(int i=2;i<x;i++)
    {
        long long int x0=x1;
        x1=x2;
        x2=x3;
        x3=x0+x1+x2;
    }
    return x3;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        long long int answer=ans(n);
        printf("case #%d:\n",i);
        printf("%lld\n",answer);
    }
    return 0;
}
