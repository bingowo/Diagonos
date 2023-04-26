#include<stdio.h>

int main()
{
    long long x,y,s=0,tran,t;
    scanf("%lld%lld",&x,&y);
    while(x&&y)
    {
        s+=4*(x/y)*y;
        x%=y;
        tran=y;
        y=x;
        x=tran;
    }
    printf("%lld",s);
}
