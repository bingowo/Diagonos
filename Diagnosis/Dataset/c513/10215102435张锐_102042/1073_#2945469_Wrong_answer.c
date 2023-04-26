#include <stdio.h>
#include <stdlib.h>
long long int power(long long int base,long long int n)
{
    long long int i;
    long long int p;
    p=1;
    for(i=1;i<=n;i++)
        p=p*base;
    return p;
}
long long int to9(long long int x)
{
    int s[20]={0},i=0;
    while(x)
    {
        int temp=x%9;x=x/9;
        s[i++]=temp;
    }
    long long int sum=0;
    for(int j=i-1;j>=0;j--)
    {
        sum=sum*10+s[j];
    }
    return sum;
}
long long int f(long long int x)
{
    int i=0;long long int sum=0,x1=x;
    while(x1)
    {
        int temp=x1%10;x1=x1/10;
        sum+=temp*power(9,i);
        i++;
    }
    return sum;
}
int main()
{
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    long long int num=f(b)-f(a)+1;
    int res=num%9;long long int r=num/9;
    long long int temp=f(num);
    long long int t=to9(temp-1);int n=0;
    for(int i=0;i<res;i++)
    {
        if((t-i)%9==0) {n=1;break;}
    }
    printf("%lld",num-r-n);
    return 0;
}
