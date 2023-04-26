#include <stdio.h>
#include <stdlib.h>

long long pwrvlue(long long x, long long y)
{
    if(x==y)return 4*x;
    else if(x%y==0)return 4*x;
    else if(y%x==0)return 4*y;
    else return x>y?4*y+pwrvlue(x-y,y):4*x+pwrvlue(y-x,x);
}
int main()
{
    long long x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",pwrvlue(x,y));
    return 0;
}
