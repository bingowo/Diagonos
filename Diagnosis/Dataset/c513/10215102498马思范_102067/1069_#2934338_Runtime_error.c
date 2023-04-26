#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void shu(int c,long long int n)
{
    int i=0;
    int a[6]={0};
    int flag=0;
    long long b=n;
    long long p=0;
    while (b>0)
    {
        a[i++]=b%10;
        b=b/10;
    }
    for(int j=0,m=i-1;j<i,m>=0;j++,m--)
    {
        if(a[j]!=a[m])
        {flag=0;break;}
        else
            flag=1;
    }
    for(int k=0;k<i;k++)
    {
        p=p*10+a[k];
    }
    if(flag==1)
    {
        printf("%d %lld",c,n);
        return;
    }
    else
    {
        c++;
        return shu(c,n+p);
    }
}
int main()
{
    long long int n;
    long long r;
    int x=0;
    scanf("%lld",&n);
    shu(x,n);
}