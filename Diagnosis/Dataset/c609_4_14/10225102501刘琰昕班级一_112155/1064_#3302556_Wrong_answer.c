#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x,y,ans=0;
    scanf("%lld%lld",&x,&y);
    do
    {
        if(x>y){long long tmp=x;x=y;y=tmp;}
        ans+=4*(y/x);
        y%=x;
    }while(y);
    printf("%lld",ans);
    return 0;
}
