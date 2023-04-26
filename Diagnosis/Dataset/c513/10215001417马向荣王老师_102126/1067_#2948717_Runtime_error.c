#include<stdio.h>
int ti(int n)
{
    int t=0;
    int a=0,b=1,c=1,i=3;
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(n==2) return 1;
    for(i=3;i<=n;i++)
    {
        t=a+b+c;
        a=b;
        b=c;
        c=t;
    }
    return t;
}
int main()
{
    int T=0;
    int j=0;
    scanf("%d\n",&T);
    for(j=0;j<T;j++)
    {
        int n=0;
        scanf("%lld\n",&n);
        long long int re=(long long int)ti(n);
        printf("case #%d:\n",j);
        printf("%lld\n",re);
    }
    return 0;
}