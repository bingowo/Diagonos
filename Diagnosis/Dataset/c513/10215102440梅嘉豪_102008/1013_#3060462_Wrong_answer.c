#include <stdio.h>
#include <string.h>
long long GCD(long long a,long long b)
{
    return b==0?a:GCD(b,a%b);
}
int main()
{
    char s[1000];
    scanf("%s",s);
    char* p=strchr(s,'.');
    long long ans=0,t,b=0,c=1,pos=0,r=3;
    if(p==NULL)
    {
        for(long long i=0;i<strlen(s);i++)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            printf("%lld\n",ans);
            ans=ans*r+t;
        }
        printf("%lld",ans);
    }
    else
    {
        while(s[pos]!='.')  pos++;
        for(long long i=0;i<pos;i++)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            ans=ans*3+t;
        }
        for(long long i=strlen(s)-1;i>pos;i--)
        {
            t=s[i]=='2'?-1:s[i]-'0';
            b=b+c*t;
            c=3*c;
        }


        if((ans>0)&&(b<0))
        {
            ans--;
            b=b+c;
        }
        else if((ans<0)&&(b>0))
        {
            ans++;
            b=-(b-c);
        }
        else if((ans<0)&&(b<0)) b=-b;


        long long x=GCD(b>0?b:-b,c);
        b=b/x;c=c/x;
        if(ans==0)  printf("%lld %lld",b,c);
        else
        {
            printf("%lld %lld %lld",ans,b,c);
        }
    }
}
