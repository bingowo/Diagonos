#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned long long ull;
ull gcd(ull a,ull b)
{
    ull temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
ull p(ull n)
{
   ull temp=1;
    for(int i=0;i<n;i++)
        temp*=10;
    return temp;
}
int main()
{
    ull b,blen,c,clen,a,fz,fm;
    int id,t;
    char s[20];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {   memset(s,20,0);
        scanf("%s",s);
         printf("case #%d:\n",i);
        a=0;id=0;
        while(s[id]!='.'&&id<strlen(s))
        {
            a=a*10+s[id]-'0';
            id++;
        }
        id++;
        b=0;blen=0;
        while(s[id]!='['&&id<strlen(s))
        {
            b=b*10+s[id]-'0';blen++;
            id++;
        }
        id++;
        c=0;clen=0;
        while(s[id]!=']'&&id<strlen(s))
        {
            c=c*10+s[id]-'0';clen++;
            id++;
        }

        if(b==0&&c==0)
        {
            printf("%llu\n",a);
        }
        else
        {
        if(c==0&&b!=0)
        {
            fm=p(blen);
            fz=b;
            printf("%llu/%llu\n",fz/gcd(fz,fm)+a*fm/gcd(fz,fm),fm/gcd(fz,fm));

        }
        else if(blen!=0)
        {
             fm=p(blen+clen)-p(blen);
             fz=b*p(clen)+c-b;
             printf("%llu/%llu\n",fz/gcd(fz,fm)+a*fm/gcd(fz,fm),fm/gcd(fz,fm));
        }
           else if(blen==0)
           {
               fm=p(clen)-1;
               fz=c;
                printf("%llu/%llu\n",fz/gcd(fz,fm)+a*fm/gcd(fz,fm),fm/gcd(fz,fm));
           }
        }
    }
    return 0;
}
