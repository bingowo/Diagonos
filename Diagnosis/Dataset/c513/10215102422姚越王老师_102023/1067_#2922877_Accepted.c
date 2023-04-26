#include<stdio.h>
unsigned long long a[75];
int main()
{
    int T,n;scanf("%d",&T);
    int i,j;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(j=3;j<=n;j++)
            a[j]=a[j-1]+a[j-2]+a[j-3];
        printf("case #%d:\n%llu\n",i,a[n]);
    }
    return 0;
}