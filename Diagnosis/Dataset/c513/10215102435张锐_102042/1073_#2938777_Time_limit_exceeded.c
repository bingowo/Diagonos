#include <stdio.h>
#include <stdlib.h>
long long unsigned power(long long unsigned base,long long unsigned n)
{
    int i;
    long long unsigned p;
    p=1;
    for(i=1;i<=n;i++)
        p=p*base;
    return p;
}
long long unsigned to9(long long unsigned x)
{
    int s[20],i=0;
    while(x)
    {
        int temp=x%9,x=x/9;
        s[i++]=temp;
    }
    long long unsigned sum=0;
    for(int j=i-1;j>=0;j--)
    {
        sum=sum*10+s[j];
    }
    return sum;
}
long long unsigned f(long long unsigned x)
{
    int i=0;long long unsigned sum=0;
    while(x)
    {
        int temp=x%10,x=x/10;
        sum+=temp*power(9,i);
        i++;
    }
    return sum;
}
int main()
{
    long long unsigned a,b;
    scanf("%llu%llu",&a,&b);
    long long unsigned num=f(b)-f(a)+1;
    int res=num%9;long long unsigned r=num/9;
    long long unsigned temp=f(num);
    long long unsigned t=to9(temp-1);int n=0;
    for(int i=0;i<res;i++)
    {
        if((t-i)%9==0) {n=1;break;}
    }
    printf("%llu",num-r-n);
    return 0;
}
