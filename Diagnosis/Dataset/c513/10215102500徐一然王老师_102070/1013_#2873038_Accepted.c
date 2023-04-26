#include<stdio.h>
#include<string.h>

int GCD(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        temp=a%b;
        a=b;b=temp;
    }
    return a;
}

int main()
{
    int count,count1,len,len1,gcd;
    long long int ans=0;
    long long int zi=0,mu=1;
    char s[30];
        scanf("%s",s);
        char *p=s;
        len=strlen(s);
        len1=len;
        while(len&&*p!='.')
        {
        if(*p=='2')
        {
            ans=ans*3-1;
        }
        else if(*p=='1')
        {
            ans=ans*3+1;
        }
        else
        {
            ans=ans*3;
        }
        p++;
        len--;
        }

        if(*p=='.')
        {
            p++;
            len--;
            for(int k=0;k<len;k++)
            {
                mu=mu*3;
            }
            while(len--)
        {
        if(*p=='2')
        {
            zi=zi*3-1;
        }
        else if(*p=='1')
        {
            zi=zi*3+1;
        }
        else
        {
            zi=zi*3;
        }
        p++;
        }
        }

        if(zi==0)
        {
            printf("%lld",ans);
            return 0;
        }

        if(ans>0)
        {


            if (zi<0)
            {
                ans--;
                zi=-zi;
                if(zi>mu)
                {
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    zi=zi-mu;
                    ans--;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
                else
                {
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
            }
            else if(zi>0)
            {
                if(zi>mu)
                {
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    zi=zi-mu;
                    ans++;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
                else
                {
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    printf("%lld %lld %lld",ans,zi,mu);
                }
            }
        }
        else if(ans<0)
        {
            if (zi<0)
            {
                ans--;
                zi=-zi;
                if(zi>mu)
                {
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    zi=zi-mu;
                    ans--;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
                else
                {
                    ans++;
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
            }
            else if(zi>0)
            {
                if(zi>mu)
                {
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    zi=zi-mu;
                    ans++;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
                else
                {
                    ans++;
                    gcd=GCD(zi,mu);
                    zi=zi/gcd;
                    mu=mu/gcd;
                    printf("%lld %lld %lld",ans,mu-zi,mu);
                }
            }
        }
        else
        {
            if(zi>0)
            {
               gcd=GCD(zi,mu);
                zi=zi/gcd;
                mu=mu/gcd;
                printf("%lld %lld",zi,mu);
            }
            else
            {   zi=-zi;
                gcd=GCD(zi,mu);
                zi=zi/gcd;
                mu=mu/gcd;
                printf("%lld %lld",-zi,mu);
            }

        }
        }