#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    long long x,y,ans=0;
    scanf("%lld%lld",&x,&y);
    while(x&&y)
    {
        ans+=x*(y/x);
        y%=x;
    }
    printf("%lld\n",ans*4);
    return 0;
}