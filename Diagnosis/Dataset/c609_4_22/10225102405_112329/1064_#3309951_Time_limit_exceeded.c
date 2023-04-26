#include<stdio.h>

int main()
{
    long long x,y,s=0,tran;
    scanf("%lld%lld",&x,&y);
    while(x&&y)
    {
        while(x>=y)
        {
            s+=4*y;
            x-=y;
        }
        //printf("%lld %lld\n",x,y);
        tran=y;
        y=x;
        x=tran;
    }
    printf("%lld",s);
}
