#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int gcd(long long int a,long long int b )
{
    if(a<b)
    {
        long long int c=a;
        a=b;
        b=c;
    }
    long long int r;
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    char s[31];
    scanf("%s",s);
    long long int a=0,b=0,c=1;
    int i=0;
    for(;i<strlen(s);i++)
    {
        if(s[i]=='.')break;
        a=a*3;
        if(s[i]=='1')a+=1;
        if(s[i]=='2')a-=1;
    }
    i++;
    for(;i<strlen(s);i++)
    {
        b=b*3;
        if(s[i]=='1')b+=1;
        else if(s[i]=='2')b-=1;
        c=c*3;
    }
    if(a>0&&b<0)
    {
        a=a-1;
        b=c+b;
    }
    if(a<0&&b>0)
    {
        a=a+1;
        b=c-b;
    }
    if(b=0)printf("%lld",a);
    else
    {long long int ret;
    ret=gcd(abs(b),abs(c));
    b=b/ret;
    c=c/ret;
    if(a==0)
    {
        printf("%lld %lld",b,c);

    }
    else printf("%lld %lld %lld",a,b,c);
    }
    return 0;
}
