#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
long long int a[101];

int main()
{   int n;
    scanf("%d",&n);
    a[0]=0;a[1]=1;a[2]=1;
    for(int i=3;i<101;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3];
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        printf("case #%d:\n",i);
        printf("%lld\n",a[x]);
    }
    return 0;
}

