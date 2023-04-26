#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int trans(int x)
{
    switch(x-1)
    {
        case 1: return 1; break;
        case 0: return 0; break;
        case -1: return 2; break;
        default: break;
    }
    return 0;
}

int main()
{
    long long a,b,c;
    scanf("%lld %lld",&a,&b);
    c=a%b;
    a/=b;
    int i=0,bgl,edl=0,x[1000]={0},y[1000]={0};
    while(a!=0)
    {
        x[i++]=a%3;
        a/=3;
    }
    bgl=i;
    i=0;
    while(b!=0)
    {
        b/=3;
        edl++;
    }
    while(c!=0)
    {
        y[i++]=c%3;
        c/=3;
    }
    int cry=0;
    i=0;
    while(i<edl)
    {
        y[i]+=(1+cry);
        if(y[i]>2)
        {
            y[i]-=3;
            cry=1;
        }
        else cry=0;
        i++;
    }
    i=0;
    while(i<bgl||cry!=0)
    {
        x[i]+=(1+cry);
        if(x[i]>2)
        {
            x[i]-=3;
            cry=1;
        }
        else cry=0;
        i++;
    }
    if(i>bgl) bgl++;
    for(i=bgl-1;i>=0;i--)
    {
        printf("%d",trans(x[i]));
    }
    if(bgl==0) printf("0");
    int flag=0;
    for(i=edl-1;i>=0;i--)
    {
        y[i]=trans(y[i]);
    }
    for(flag=0;flag<edl;flag++)
    {
        if(y[flag]!=0) break;
    }
    if(edl!=flag) printf(".");
    for(i=edl-1;i>=flag;i--)
    {
        printf("%d",y[i]);
    }
    return 0;
}
