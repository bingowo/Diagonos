#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void swap(long long* x, long long* y)
{
    long long temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    long long x,y,ans=0;
    scanf("%lld%lld",&x,&y);
    while(x&&y)
    {
        
        ans+=y*(x/y);
        x%=y;
    }
    printf("%lld\n",ans*4);
    return 0;
}