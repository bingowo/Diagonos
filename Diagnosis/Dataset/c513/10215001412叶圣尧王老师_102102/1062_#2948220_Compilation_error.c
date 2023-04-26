#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long f(int n);
{
    if(n==0)return 1;
    else if(n==1)return 2;
    else if(n==3)return 4;
    else if(n==4)return 8;
    else
        return f(n-1)+f(n-2)+f(n-3)+f(n-4);
}

int main()
{
    int i,j,T;int a[4]={1,2,4,8},n;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        long long sum=f(n);
        printf("%lld\n",sum);
    }
}
