#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int _pow(int n,int m)
{
    int ans=1;
    while(m){
        if(m%2)ans=ans*n%10007;
        n=n*n%10007;
        m>>=1;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    int fac[10009];
    fac[0]=1;
    for(int i=1;i<=10000;i++)fac[i]=fac[i-1]*i%10007;
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        int a,b,k,n,m;
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        a%=10007;
        b%=10007;
        long long ans=1;
        ans*=_pow(a,n)%10007;
        ans*=_pow(b,m)%10007;
        ans=ans*fac[k]%10007*_pow(fac[n],10005)%10007*_pow(fac[k-n],10005)%10007;
        printf("%lld\n",ans);
    }
    return 0;
}
