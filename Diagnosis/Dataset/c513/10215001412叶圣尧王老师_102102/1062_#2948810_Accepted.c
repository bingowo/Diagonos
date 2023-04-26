#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long a[51]={0};
long long f(int n)
{
    if(n==0)return 0;
    else if(n==1)return 1;
    else if(n==2)return 2;
    else if(n==3)return 4;
    else if(n==4)return 8;
    else if(a[n]>0)return a[n];
    else
        {
        a[n]=f(n-1)+f(n-2)+f(n-3)+f(n-4);
        return a[n];
        }
}

int main()
{
    int T;int n;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        printf("%lld\n",f(n));
    }
}
