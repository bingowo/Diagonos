#include <stdio.h>
#include <stdlib.h>

long long ans=0;

void find(long long x,long long y){
    if (y==0) return;
    ans+=(x/y)*4*y;
    find(y,x%y);
}

int main()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    if (x>y) find(x,y);
    else find(y,x);
    printf("%lld",ans);
    return 0;
}
