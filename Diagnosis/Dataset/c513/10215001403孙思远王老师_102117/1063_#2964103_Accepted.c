#include <stdio.h>
#include <stdlib.h>

unsigned long long int zh(long long int x,long long int y,long long int all)
{
    if(y!=0&&x/y>1)
    {
        all+=4*y*(x/y);
        zh(y,x%y,all);
    }
    else if(x==y||y==0)
    {
        all+=4*y;
        return all;
    }
    else
    {
        all+=4*y;
        zh(y,x-y,all);
    }
}
int main()
{
    long long int x,y,d,all=0;
    scanf("%lld%lld",&x,&y);
    if(x<y)
    {
        d=x;
        x=y;
        y=x;
    }
    all=zh(x,y,all);
    printf("%lld",all);
    return 0;
}
