#include<stdio.h>
int main()
{
    int T,n;
    long long a[51];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=8;
    for(int i=5;i<51;i++)
        a[n]=a[n-1]+a[n-2]+a[n-3]+a[n-4];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%lld",i,a[n]);
    }
    return 0;
}