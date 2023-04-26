#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int gcd(long long m,long long n)
{
    if(m<n){int t=m;m=n;n=t;}
    if(n==0)return m;
    else{
    m=m%n;
    return gcd(m,n);
    }

}

int main()
{
    int n;scanf("%d",&n);
    long long x=0,y=0,a,b,i,j;char s[1001];
    for(int t=0;t<n;t++)
    {
    x=0;y=0;
    scanf("%s",s);
    for(i=0;s[i]!='/';i++)x=x*10+s[i]-'0';
    for(i=i+1;i<strlen(s);i++)y=y*10+s[i]-'0';
    if(t==0){a=x;b=y;}
    else
    {
        a=a*y+b*x;b=b*y;
        int m=gcd(a,b);
        a/=m;b/=m;
    }
    }
    printf("%lld/%lld",a,b);
}