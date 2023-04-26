#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    long long a[74];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<74;i++)
    a[i]=a[i-2]+a[i-1];
    for(int i=0;i<T;i++)
    {
        int n=0;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,a[n]);
    }
    return 0;
}