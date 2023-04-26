#include<stdio.h>

unsigned long long int GCD(unsigned long long int x,long long int y)
{
    if(x%y == 0)
        return y;
    else
        return GCD(y,x%y);
}

int main()
{
    unsigned long long int x,y;
    scanf("%llu%llu",&x,&y);
    unsigned long long int S,num,gcd;
    gcd = GCD(x,y);
    unsigned long long int W[gcd];
    S=x*y;
    for(unsigned long long int i=1;i<(gcd+1),x%i==0,y%i==0;i++)
    {
        num = S/(i*i);
        W[i] = num*4*i;
    }
    unsigned long long int ans=W[1];
    for(unsigned long long int i=1;i<(gcd+1),x%i==0,y%i==0;i++)
    {
        if(W[i]>ans);
        else
            ans = W[i];
    }
    printf("%llu\n",ans);
    return 0;
}
