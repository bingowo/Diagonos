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
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,a[n]);
    }
    return 0;
}