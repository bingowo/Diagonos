#include<stdio.h>
#include<string.h>
#include<math.h>

int transform(int x)
{
    switch (x-1)
    {
        case 1:return 1;break;
        case 0:return 0;break;
        case -1:return 2;break;
        default:break;
    }
    return 0;
}

int main()
{
    long long a,b,c;
    scanf("%lld %lld",&a,&b);
    a=abs(a)
    c=a%b;
    a=a/b;

    int i=0,frontlen,behindlen=0,threefront[1000]={0},threebehind[1000]={0};
    while (a!=0)
    {
        threefront[i++]=a%3;
        a/=3;
    }
    frontlen=i;
    i=0;
    while (c!=0)
    {
        threebehind[i++]=c%3;
        c/=3;
    }
    while (b!=1)
    {
        b/=3;
        behindlen++;
    }
    
    int carry=0;
    i=0;
    while (i<behindlen)
    {
        threebehind[i]+=(1+carry);
        if(threebehind[i]>2)
        {
            threebehind[i]-=3;
            carry=1;
        }
        else carry=0;
        i++;
    }
    i=0;
    while(i<frontlen || carry!=0)
    {
        threefront[i]+=(1+carry);
        if(threefront[i]>2)
        {
            threefront[i]-=3;
            carry=1;
        }
        else carry=0;
        i++;
    }
    if(i>frontlen) frontlen++;
    for(i=frontlen-1;i>=0;i--) printf("%d",transform(threefront[i]));
    if(frontlen==0) printf("0");
    
    int flag=0;
    for(i=behindlen-1;i>=0;i--) threebehind[i]=transform(threebehind[i]);
    for(flag=0;flag<behindlen;flag++)
    {
        if(threebehind[flag]!=0) break;
    }
    if(behindlen!=flag) printf(".");
    for(i=behindlen-1;i>=flag;i--) printf("%d",threebehind[i]);
    
    return 0;
}