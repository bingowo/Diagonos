#include <stdio.h>
#include <stdlib.h>


typedef long long int lli;


int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    lli dp[n];
    lli in=0,out=0;
    dp[0]=a;
    for(int i=0;i<n;i++){
        dp[i]=i;
    }
    printf("%lld",dp[x]);
}
