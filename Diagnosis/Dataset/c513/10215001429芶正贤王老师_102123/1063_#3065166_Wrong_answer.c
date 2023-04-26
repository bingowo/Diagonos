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
    long long int i,S,num,min,max,gcd;
    if(x<y)
    {
        min = x;
        max = y;
    }
        
    else
    {
        min = y;
        max = x;
    }
        gcd = GCD(max,min);
    long long int W[gcd];
    S=x*y;
    for(i=1;i<gcd+1,x%i == 0,y%i == 0;i++)
    {
        num = S/(i*i);
        W[i] = num*i*4;
    }
    long long int ans=W[1];
    for(i=1;i<min+1;i++)
    {
        if(W[i]>ans);
        else
            ans = W[i];
    }
    printf("%lld\n",ans);
    return 0;
}
