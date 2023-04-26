#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
先除去包含9的，剩余的相当于连续的9进制数
在除去s是9的倍数的
*/

long long f(long long x)
{
    char t[20]={0};
    sprintf(t,"%lld",x);
    long long n=0;
    for(int i=0;i<strlen(t);i++)
        n=n*9+t[i]-'0';
    return n;
}
long long g(long long a,long long b)
{
    long long num=0;
    for(;a<=b;a++)
    {
        char t[20]={0};
        sprintf(t,"%lld",a);
        int i=0;
        for(;i<strlen(t);i++)
            if(t[i]=='9') break;
        if(i==strlen(t)&&a%9==0) num++;//计算剩余那一组不含9但是就懂得倍数的个数

    }
    return num;
}

int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long int num=0;
    num=f(b)-f(a)+1;//把a,b看为9进制下两个数，化为十进制数相减加一，即为数的个数
    long long t1=f(b-b%10)/9+g(b-b%10,b),t2=f(a-a%10)/9+g(a-a%10,a);
    printf("%lld",num-t1+t2);
    return 0;
}