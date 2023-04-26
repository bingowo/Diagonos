#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void zheng(char *s);
void fen(char *s,int i,int len);

int main()
{
    char s[10000];
    int i,flag=1,len;
    gets(s);
    len=strlen(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='.')
        {
            flag=0;
            break;
        }
    }
    if(flag)
        zheng(s);
    else
        fen(s,i,len);
    return 0;
}

void zheng(char *s)
{
    int i;
    long long int a=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='2')
            a=a*3-1;
        else if(s[i]=='1')
            a=a*3+1;
        else if(s[i]=='0')
            a=a*3;
    }
    printf("%lld",a);
}
void fen(char *s,int wei,int len)
{
    int i;
    long long int a=0;
    for(i=0;i<wei;i++)
    {
        if(s[i]=='2')
            a=a*3-1;
        else if(s[i]=='1')
            a=a*3+1;
        else if(s[i]=='0')
            a=a*3;
    }
    int j;
    long long int mu,z=0,zi,bei;
    j=len-wei-1;
    mu=pow(3,j);
    for(i=wei+1;i<len;i++)
    {
        if(s[i]=='2')
            z=z*3-1;
        else if(s[i]=='1')
            z=z*3+1;
        else if(s[i]=='0')
            z=z*3;
    }
    if(a>=0)
    {
    if(z>0&&a!=0)
    {
        zi=z;
        for(bei=mu;bei>=zi;bei--)
        {
            if(mu%bei==0&&zi%bei==0)
            {
                mu/=bei;
                zi/=bei;
                break;
            }
        }
        printf("%lld %lld %lld",a,zi,mu);

    }
    if(z>0&&a==0)
    {
        zi=z;
        for(bei=mu;bei>=zi;bei--)
        {
            if(mu%bei==0&&zi%bei==0)
            {
                mu/=bei;
                zi/=bei;
                break;
            }
        }
        printf("%lld %lld",zi,mu);

    }
    else if(z<0&&a>1)
    {
        zi=mu+z;
        a--;
        for(bei=mu;bei>zi;bei--)
        {
            if(mu/bei==0&&zi/bei==0)
            {
                mu/=bei;
                zi/=bei;
            }
        }
        printf("%lld %lld %lld",a,zi,mu);
    }
    else if(z<0&&a==1)
    {
        zi=mu+z;
        for(bei=mu;bei>=zi;bei--)
        {
            if(mu/bei==0&&zi/bei==0)
            {
                mu/=bei;
                zi/=bei;
            }

        }
         printf("%lld %lld",zi,mu);
    }
    else if(z<0&&a==0)
    {
        zi=z;
        int kk=-zi;
        for(bei=mu;bei>=kk;bei--)
        {
            if(mu/bei==0&&zi/bei==0)
            {
                mu/=bei;
                zi/=bei;
            }

        }
        printf("%lld %lld",zi,mu);
    }
    else if(z=0)
    {
        printf("%lld",a);
    }
    }
    else if(a<0)
    {
    if(z>0)
    {
        zi=mu-z;
        a++;
        for(bei=mu;bei>=zi;bei--)
        {
            if(mu%bei==0&&zi%bei==0)
            {
                mu/=bei;
                zi/=bei;
                break;
            }
        }
        printf("%lld %lld %lld",a,zi,mu);

    }
    if(z<0)
    {
        zi=mu+z;
        zi=-zi;
        for(bei=mu;bei>=zi;bei--)
        {
            if(mu%bei==0&&zi%bei==0)
            {
                mu/=bei;
                zi/=bei;
                break;
            }
        }
        printf("%lld %lld %lld",a,zi,mu);
    }
    else if(z=0)
    {
        printf("%lld",a);
    }
    }
}