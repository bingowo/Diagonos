#include <stdio.h>

long long r=0;
void count(long long x,long long y)
{
    long long c,d;
    if(x<y){c=x;x=y;y=c;}
    r=r+y*4;
    d=x-y;
    if(d!=0){x=y;y=d;count(x,y);}

}
int main()
{

    long long x,y;
    scanf("%lld %lld",&x,&y);
    count(x,y);
    printf("%lld",r);
    return 0;


}


