#include<stdio.h>
long long int min(long long int a,long long int b)
{
    return (a<b)?a:b;
}
int main()
{
    long long int m,n;
    scanf("%lld %lld",&m,&n);
    long long int tmp;
    long long int sum=0;
    while(m!=n)
    {
        tmp=min(m,n);
        sum+=4*tmp;
        if(m>n) m-=tmp;
        else n-=tmp;
    }
    sum+=4*m;
    printf("%lld",sum);
}
