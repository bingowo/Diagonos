#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    long long int a[51];
    memset(a, 0, sizeof(a));
    a[1]=1;
    a[2]=2;
    a[3]=4;
    a[4]=8;
    for(int i=5;i<=50;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",a[n]);
    }
    return 0;
}
