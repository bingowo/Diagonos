#include <stdio.h>
#include <stdlib.h>
long long int s(long long int x,long long int y)
{
    long long int res=x%y,num=x/y;
    if(res==0) return 4*y*num;
    else return 4*y*num+s(y,res);
}
int main()
{
    long long int x,y;
    scanf("%lld%lld",&x,&y);
    long long int ans=s(x,y);
    printf("%lld\n",ans);
    return 0;
}
