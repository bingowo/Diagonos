#include<stdio.h>
long long labor=0;
long long solve(long long a, long long b)
{
    long long t;
    if(a<b)
    {
        t=a; a=b; b=t;
    }
    if(b>0){
        labor+=b*4; a-=b; solve(a,b);
    }
    return labor;
}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    printf("%lld",solve(x,y));
    return 0;
}