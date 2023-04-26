#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    long long int a[74];
    memset(a,0,sizeof(a));
    a[0]=0;
    a[1]=1;
    a[2]=1;
    long long sum=0;
    for(int j=3;j<74;j++)
        a[j]=a[j-1]+a[j-2]+a[j-3];
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        sum=a[n];
        printf("case #%d:\n",i);
        printf("%lld\n",sum);
    }
    return 0;
}