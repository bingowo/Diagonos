#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long a[51]={0};
long long f(int n)
{
    int result;
    if(n==0)return 0;
    else if(n==1)return a[1]=1;
    else if(n==2)return a[2]=2;
    else if(n==3)return a[3]=4;
    else if(n==4)return a[4]=8;
    else
        return a[n]=f(n-1)+f(n-2)+f(n-3)+f(n-4);
}


int main()
{
    int T;int n;
    scanf("%d",&T);
    long long z=long long f(50);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
}
