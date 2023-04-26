#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long x,y,ans=0;
    scanf("%lld%lld",&x,&y);
    do
    {
        if(x>y){long long tmp=x;x=y;y=tmp;}
        ans+=4*(y/x)*x;
        y%=x;
    }while(y);
    printf("%lld",ans);
    return 0;
}
