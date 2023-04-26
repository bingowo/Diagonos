
#include <stdio.h>
#include <stdlib.h>

long long int cal(long long int x,long long int y)
{
    long long ans;
    if(x<y)
    {
        long long int temp=x;
        x=y;
        y=temp;
    }
    if(y==0) return 0;
    ans=x/y*y*4+cal(y,x%y);
    return ans;
}

int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",cal(x,y));
    return 0;
}