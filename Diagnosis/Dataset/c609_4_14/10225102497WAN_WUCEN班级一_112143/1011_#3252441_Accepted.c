#include <stdio.h>
#include <stdlib.h>

#define base 3

int main()
{
    char in[30],sign=0,signd;
    short table[3]={0,1,-1},i=0,n=0,point=0;
    long long out=0,numerator=0,denominator=1;
    while(scanf("%c",in+i)!=EOF)if(in[i++]=='.')point=i-1;
    i--;
    n=i;
    if(!point)point=n;
    for(i=0;i<point;i++)
        out=out*base+table[in[i]-48];
    sign=(out<0)?-1:1;
    out=(out<0)?-out:out;
    for(i++;i<n;i++)
        {denominator*=base;
        numerator=numerator*base+table[in[i]-48];}
    signd=(numerator<0)?-1:1;
    numerator=(numerator<0)?-numerator:numerator;
    numerator=(signd*sign<0&&out)?denominator-numerator:numerator;
    if(out>1)printf("%lld ",(signd*sign<0&&point!=n)?(out-1)*sign:out*sign);
    else if(signd*sign>=0&&out==1)printf("%lld ",out*sign);
    else if(!out&&point==n)printf("0");
    if(point!=n&&out)printf("%lld %lld",numerator,denominator);
    else if(point!=n)printf("%lld %lld",signd*numerator,denominator);
}
