#include<stdio.h>

long long sum(long long x)
{
    if(x==0) return 1;
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 4;
    return (sum(x-1)+sum(x-2)+sum(x-3)+sum(x-4));
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",t);
        printf("%lld\n",sum(n));
    }
    return 0;
}
