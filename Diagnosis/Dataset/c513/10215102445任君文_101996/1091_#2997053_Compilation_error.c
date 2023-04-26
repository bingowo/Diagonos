#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long fs(long long a, long long b,int n)
{
    long long ra,rb;
    if(n==1)
        return b;
    else
    {
        ra=a*a-b*b;
        rb=a*b+a*b;
        return (fs(ra,rb,n-1);
    }
}
long long zs(long long a, long long b,int n)
{
    long long ra,rb;
    if(n==1)
        return a;
    else
    {
        ra=a*a-b*b;
        rb=a*b+a*b;
        return (fs(ra,rb,n-1);
    }
}
long long mypow(int n,int m)
{
    if(m==0)
        return 1;
    else if(m==1)
        return n;
    else 
        return (n*mypow(n,m-1));
}
int main()
{
    char c;
    int i=0;
    long long a=0,b=0,n=0;
    int k1=1,k2=1;
    int f=0;
    long long resb=0,resa=0;
    while((c=getchar())!='\n')
    {
        if(c==' ')
        {
            scanf("%d",&n);
            break;
        }
        else if(c=='-')
        {
            if(i==0)
            {
                k1=-1;
            }
            else
            {
                k2=-1;
                f=1;
            }
        }
        else if(c=='+')
        {
            f=1;
        }
        else if(('0'<=c)&&(c<='9'))
        {
            if(f==0)
            {
                a=a*10+(c-'0');
            }
            else if(f==1)
            {
                b=b*10+(c-'0');
            }
        }
        else if(c=='i')
        {
            if(b==0)
            {
                b=1;
            }
        }
        i++;
    }
    b=b*k2;
    a=a*k1;
    if(a==0)
    {
        if(b==0)
            printf("0\n");
        else
        {
            resb=mypow(b,n);
            if((n%4)==0)
            {
                printf("%lld\n",resb);
            }
            else if((n%4)==1)
            {
                printf("%lldi\n",resb);
            }
            else if((n%4)==2)
            {
                printf("-%lld\n",resb);
            }
            else if((n%4)==3)
            {
                printf("-lldi\n",resb);
            }
        }
    }
    else
    {
        if(b==0)
        {
            resa=mypow(a,n);
            printf("%lld",resa);
        }
        else
        {
            resa=zs(a,b,n);
            resb=fs(a,b,n);
            if(resb<0)
            {    
                resb=-resb;
                printf("%lld-%lldi\n",resa,resb);
            }
            else if(resb==0)
                printf("%lld",resa);
            else
                printf("%lld+%lldi",resa,resb);
        }
    }
    return 0;
}