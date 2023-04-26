#include<stdio.h>
int main()
int weishu(int m)
{
    int result=0;
    while(m/3!=0)
    {
        result++;
        m=m/3;
    }
    return result;
}
int length(long long int m)
{
    int j=0;
    char a[weishu(m)+1];
    for(int i=0;i<weishu(m)+1;i++)
    {
        a[weishu(m)-i]=m%3+'0';
        m=m/3;
    }
}
{
    long long int a;
    long long int b;
    scanf("%lld",&a);
    scanf("%lld",&b);
    long long int c=a%b;
    long long int d=a-c;
    int w=weishu(b);
    if(w==0)
    {
        char changdu[weishu(a)+1];
        for(int i=0;i<weishu(a)+1;i++)
        {
            changdu[weishu(a)-i]=a%3+'0';
            a=a/3;
        }
        char link[weishu(a)+2];
        for(int j=0;j<weishu(a)+1;j++)
        {
            if()
        }
    }
}