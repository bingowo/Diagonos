#include <stdio.h>
#include <stdlib.h>

int cnt;
long long int trans(long long int n);
int judge(long long int a);
long long int palin(long long int n);
int main()
{
   long long int n;
   cnt=0;
   scanf("%lld",&n);
   long long int res=palin(n);
   printf("%d %lld\n",cnt,res);
   return 0;
}
long long int trans(long long int n)//得到回文数m
{
    long long int m=0;
    int t;
    while(n>0)
    {
        t=n%10;
        m=m*10+t;
        n/=10;
    }
    return m;
}

int judge(long long int a)//判断是否是回文数
{
    long long int b=trans(a);
    while(a>0&&b>0)
    {
        if((a%10)!=(b%10)){return 0;}
        a/=10;b/=10;
    }
    if((a+b)>0&&(a==0||b==0))return 0;
    return 1;
}
long long int palin(long long int n)
{
    long long int res=trans(n)+n;
    cnt++;
    if(judge(res))return res;
    else return(palin(res));
}

