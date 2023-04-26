#include <stdio.h>
#include <stdlib.h>
long long int Mic(int n)
{
    long long int a[100];
    a[0]=0;
    a[1]=1;
    a[2]=1;
    if(n>2)
    {
        for(int i=3;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
    }
    return a[n];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;;
        scanf("%d",&n);
        printf("case #%d:\n%lld\n",i,Mic(n));
    }
}
