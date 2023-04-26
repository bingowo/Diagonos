#include <stdio.h>
int main()
{
    long long int x=0,y=0,t=0;
    scanf("%lld %lld",&x,&y);
    long long int sum=0;
    while(x!=0 && y!=0)
    {
        if(x>y) {t=x;x=y;y=t;}
        long long int num=0;
        num=y/x;
        y=y-num*x;
        sum+=num*4*x;
    }
    printf("%lld",sum);
    return 0;
}