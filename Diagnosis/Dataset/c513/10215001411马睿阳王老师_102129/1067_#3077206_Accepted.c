#include<stdio.h>

int main()
{
    int T,i,k,n;
    long long int v,s[75];
    scanf("%d",&T);
    for(i=3;i<75;i++)
    {
        s[0]=0;s[1]=1;s[2]=1;
        s[i]=s[i-1]+s[i-2]+s[i-3];
    }
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        v=s[n];
        printf("case #%d:\n",i);
        printf("%lld\n",v);
    }
    return 0;
}
