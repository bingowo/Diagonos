#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int Robin(long long int x,long long int y)
{
    if(x<y)
    {
        int temp=x;x=y;y=temp;
    }
    if(x==y) return 4*x;
    else if(x%y==0) return 4*y*(x/y);
    else
    {
        return(4*y+Robin(x-y,y));
    }
}
int main()
{
    long long int x,y,v;
    scanf("%lld %lld",&x,&y);
    v=Robin(x,y);
    printf("%lld",v);
    return 0;
}
