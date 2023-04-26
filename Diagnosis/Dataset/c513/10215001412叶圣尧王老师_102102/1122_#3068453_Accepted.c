#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        long long n;scanf("%lld",&n);
        int a[6]={0};long long d[6]={1};
        for(int i=1;i<6;i++)
            d[i]=d[i-1]*2333;
        for(int i=5;i>=0;i--)
        {
            a[i]=n/d[i];
            n=n%d[i];
        }
        int k=5;
        while(a[k]==0)k--;
        for(int i=k;i>0;i--)printf("%d ",a[i]);
        printf("%d\n",a[0]);
    }
}