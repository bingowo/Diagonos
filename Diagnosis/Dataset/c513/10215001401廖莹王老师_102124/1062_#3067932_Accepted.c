#include <stdio.h>
#include <stdlib.h>

int main()
{   int i=0;
    long long a[55]={0};
    a[1]=1;a[2]=2;a[3]=4;a[4]=8;
    for(i=5;i<=50;i++)a[i]=a[i-4]+a[i-3]+a[i-2]+a[i-1];
    int n;
    int b[15]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<n;i++){printf("case #%d:\n",i);printf("%lld\n",a[b[i]]);}
    return 0;
}
