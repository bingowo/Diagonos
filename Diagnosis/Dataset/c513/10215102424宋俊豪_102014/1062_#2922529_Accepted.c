
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
long long int a[101];

int main()
{   int n;
    scanf("%d",&n);
    a[1]=1;a[2]=2;a[3]=4;a[4]=8;
    for(int i=5;i<101;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    for(int i=0;i<n;i++)
    {
        long long int x;
        scanf("%lld",&x);
        printf("case #%d:\n",i);
        printf("%lld\n",a[x]);
    }
    return 0;
}
