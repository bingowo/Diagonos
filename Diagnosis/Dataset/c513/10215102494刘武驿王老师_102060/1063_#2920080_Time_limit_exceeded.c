#include<stdio.h>
long long int min(long long int a,long long int b)
{
    return (a<b)?a:b;
}
long long int GCD(long long int m,long long int n)
{   long long int a,b;
    if (m>n)
    {
        a=m;
        m=n;
        n=a;
    }
    
    if (n%m==0) return m;
    if (n%m!=0) return GCD(n-m,m);
    }
int main()
{
    long long int m,n;
    scanf("%lld %lld",&m,&n);
    long long int tmp;
    long long int sum=0;
    if(m==1)
    {
        printf("%lld",4*n);
        return 0;
    }
    if(n==1)
    {
        printf("%lld",4*m);
        return 0;
    }
    long long int yue=GCD(m,n);
    m/=yue;
    n/=yue;
    while(m!=n)
    {
        tmp=min(m,n);
        sum+=4*tmp;
        if(m>n) m-=tmp;
        else n-=tmp;
    }
    sum+=4*m;
    printf("%lld",sum*yue);
}
