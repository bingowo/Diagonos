#include <stdio.h>
#include <stdlib.h>
long long GCD(long long a,long long b);
int main()
{
    long long a=0,b=0,c=1;
    char s[100],*p;
    p=s;
    scanf("%s",s);
    while(*p)
    {
        if(*p=='.') break;
        if(*p=='2') a=a*3-1;
        else a=a*3+(*p-'0');
        p++;
    }
    p++;
    while(*p)
    {
        if(*p=='2') b=b*3-1;
        else    b=b*3+(*p-'0');
        c=c*3;
        p++;
    }
    if(a>0&&b<0)
    {
        a=a-1;
        b=c+b;
    }
    else if(a<0&&b>0)
    {
        a=a+1;
        b=c-b;
    }
    // printf("%d %d %d\n",a,b,c);
    if(b!=0)
    {
        int d=GCD(abs(b),abs(c));
        // printf("%d\n",d);
        b=b/d;c=c/d;
    }

    // if(a!=0)    printf("%lld",a);
    // if(b!=0)    printf("%lld %lld",b,c);
    if(a!=0&&b!=0)  printf("%lld %lld %lld",a,b,c);
    else if(a==0&&b==0) printf("0");
    else if(a==0)   printf("%lld %lld",b,c)
    else if(b==0)   printf("%lld",a);

}
long long GCD(long long a,long long b)
{
    return b==0?a:GCD(b,a%b);
}
