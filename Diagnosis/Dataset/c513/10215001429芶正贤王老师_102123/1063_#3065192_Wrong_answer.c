#include<stdio.h>
#include<stdio.h>
unsigned long long f(unsigned long long x,unsigned long long y)
{
    unsigned long long num,w=0,temp;
    if(y=1)
    {
        w+=4*x;
    }
    else
    {
        num=x/y;
        w+=num*4*y;
        temp=x;
        x=y;
        y=temp-num*y;
    }
    return w;
}
int main()
{
    unsigned long long x,y,ans;
    scanf("%llu%llu",&x,&y);
    ans = f(x,y);
    return 0;
    
}
