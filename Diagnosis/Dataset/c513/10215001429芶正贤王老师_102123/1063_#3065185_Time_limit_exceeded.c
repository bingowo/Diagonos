#include<stdio.h>

long long int GCD(long long int x,long long int y)
{
    if(x%y == 0)
        return y;
    else
        return GCD(y,x%y);
}

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    long long int i,S,num,gcd;
    gcd = GCD(x,y);
    long long int W[gcd];
    S=x*y;
    for(i=1;i<(gcd+1),x%i == 0,y%i == 0;i++)
    {
        num = S/(i*i);
        W[i] = num*4*i;
    }
    long long int ans=W[1];
    for(int j=1;j<(gcd+1),x%j == 0,y%j == 0;i++)
    {
        if(W[j]>ans);
        else
            ans = W[j];
    }
    printf("%lld\n",ans);
    return 0;
}
