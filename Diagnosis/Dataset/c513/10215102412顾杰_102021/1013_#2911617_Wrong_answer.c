#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
long long GCD(long long a,long long b)
{
    if(a<b){long long t=a;a=b;b=t;}
    return b==0?a:GCD(a%b,b);
}
int main() {
    int i,j,k;
    char s[31],*p=s;
    long long ansa=0,ansb=0,ansc=1;
    scanf("%s",s);
    while(*p!='.'&&*p)
    {
        ansa*=3;
        if(*p=='1')ansa++;
        if(*p=='2')ansa--;
        p++;
    }
    if(*p++=='.')
        while(*p)
    {
        ansb*=3;
        ansc*=3;
        if(*p=='1')ansb++;
        if(*p=='2')ansb--;
        p++;
    }
    if(!ansb)printf("%lld",ansa);
    else
    {
        long long t=GCD(abs(ansb),abs(ansc));
        ansb/=t;ansc/=t;
        if(ansa>0&&ansb<0){ansa--;ansb+=ansc;}
        if(ansa<0&&ansb>0){ansa++;ansb-=ansc;}
        if(ansb<0)ansb*=-1;
        if(!ansa)printf("%lld %lld",ansb,ansc);
        else printf("%lld %lld %lld",ansa,ansb,ansc);
    }

    return 0;
}
