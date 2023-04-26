#include<stdio.h>

long long int effort_min(long long int x,long long int y)
{
    if(x==1||y==1) return x*y*4;
    else if(x==y) return 4*x;
    else
    {
        long long int L=x>y?x:y;
        long long int S=x<y?x:y;
        return 4*S+effort_min(L-S,S);
    }
}

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",effort_min(x,y));
    return 0;
}
