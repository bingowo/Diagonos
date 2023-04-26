#include <stdio.h>
#include <stdlib.h>



int main()
{
    long long x,y,i;
    scanf("%lld %lld",&x,&y);
    if(x>y){i=x;x=y;y=i;}
    long long ans=0;
    while(x){long long a=y/x;ans+=4*x*a;y%=x;i=x;x=y;y=i;}
    printf("%lld",ans);
    return 0;
}
