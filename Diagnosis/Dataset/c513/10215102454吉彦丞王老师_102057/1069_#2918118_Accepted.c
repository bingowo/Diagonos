#include<stdio.h>
long long int zhishu(int n)
{
    int a=1;
    for(int i=0;i<n;i++)
    {
        a=a*10;
    }
    return a;
}
long long int back(long long int a)
{
    int t=0;
    long long int b=a;
    while(b>0)
    {
        b=b/10;
        t++;
    }
    long long int c=0;
    for(int i=0;i<t;i++)
    {
        c=c+a%10*zhishu(t-i-1);
        a=a/10;
    }
    return c;
}
int sure(long long int a)
{
    if(a==back(a))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int m=back(n);
    long long int s=m+n;
    int t=1;
    while(sure(s)!=1)
    {
        t++;
        n=s;
        m=back(n);
        s=m+n;
    }
    printf("%d ",t);
    printf("%lld\n",s);
    return 0;
}