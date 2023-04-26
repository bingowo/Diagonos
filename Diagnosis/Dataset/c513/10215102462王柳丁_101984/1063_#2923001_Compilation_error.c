#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int count(long long int x,long long int y)
{
    if(x<y){
        long long int a;
        a=x;x=y;y=a;
    }
    res=(x==y)?4*x:count(x-y,x);
    return res;
}

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int res=0;
    res=count(x,y);
    printf("%lld\n",res);
    return 0;
}
