#include <stdio.h>
#include <stdlib.h>
long long int solve(long long x,long long y)
{
    if(x==y) return 4*x;
    if(x>y) return solve(y,x-y)+4*y;
    if(x<y) return solve(x,y-x)+4*x;
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",solve(x,y));
    return 0;
}
