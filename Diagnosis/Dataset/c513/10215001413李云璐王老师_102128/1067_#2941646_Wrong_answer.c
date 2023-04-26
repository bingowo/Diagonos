#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        long long int a[x+1];
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(int k=3;k<=x;k++)
        a[k]=a[k-1]+a[k-2]+a[k-3];
        printf("case #%d:\n",i);
        printf("%lld\n",a[x]);
    }
    return 0;
}