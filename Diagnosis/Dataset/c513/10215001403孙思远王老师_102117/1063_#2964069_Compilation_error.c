#include <stdio.h>
#include <stdlib.h>

int zh(long long int x,long long int y,long long int all)
{
    long long int mi,ma;
    if(x>y)
    {
        ma=x;
        mi=y;
    }
    else if(x<y)
    {
        ma=y;
        mi=x;
    }
    else
    {
        all+=4*x;
        return all;
    }
    all+=4*mi;
    zh(mi,ma-mi,all);#include <stdio.h>
#include <stdlib.h>

unsigned long long int zh(long long int x,long long int y,long long int all)
{
    long long int mi,ma;
    if(x>y)
    {
        ma=x;
        mi=y;
    }
    else if(x<y)
    {
        ma=y;
        mi=x;
    }
    else
    {
        all+=4*x;
        return all;
    }
    all+=4*mi;
    zh(mi,ma-mi,all);
}
int main()
{
    long long int x,y,all=0;
    scanf("%lld%lld",&x,&y);
    all=zh(x,y,all);
    printf("%lld",all);
    return 0;
}

}
int main()
{
    long long int x,y,all=0;
    scanf("%lld%lld",&x,&y);
    all=zh(x,y,all);
    printf("%lld",all);
    return 0;
}
