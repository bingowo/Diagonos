#include <stdio.h>
#include <stdlib.h>
long long int solve(long long x,long long y)
{
    if(y==0) return 0;
    if(x==y) return 4*x;
    else return solve(y,x%y)+4*y*(x/y);
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",solve(x,y));
    return 0;
}
