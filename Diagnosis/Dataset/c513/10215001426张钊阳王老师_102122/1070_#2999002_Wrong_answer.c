#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long num(int n);
    int n;
    while(scanf("%d",&n))
    {
        if(n==-1) break;
        else printf("%lld",(1<<n)-num(n));
    }
    return 0;
}

long long num(int n)
{
    long long nu[25];
    for(int i=1;i<=n;i++)
    {
        if(i<=2) nu[i]=0;
        if(i==3) nu[i]=1;
        if(i>3) nu[i]=2*nu[i-1]+((1<<i-1)-nu[i-1]);
    }
    return nu[n];
}
