#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long f(int n)
{
    if(n==1||n==2)return 1;
    else return f(n-1)+f(n-2)+f(n-3);
}

long long it(int n)
{
    long long *arr;
    arr[0]=0;
    arr[1]=1;
    arr[2]=1;
    for(int i=3;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    return arr[n];
}


int main()
{
    int T,n;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        scanf("%d",&n);
        
        printf("%lld",it(n));
    }
}