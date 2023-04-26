#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int miao(long long int n)
{
    if(n%9==0) return 0;
    else
    {
        int a[100],i=0;
        while(n!=0)
        {a[i]=n%10;
        n/=10;
        i++;}//i是a中元素个数
        for(int k=0;k<i;k++)
        {if(a[k]==9) return 0;}
        return 1;
        
    }
}
int main()
{
    long long int a,b,count=0;
    scanf("%lld%lld",&a,&b);
    for(long long int i=a;i<=b;i++)
    if(miao(i)==1) count++;
    printf("%d",count);
    return 0;
}