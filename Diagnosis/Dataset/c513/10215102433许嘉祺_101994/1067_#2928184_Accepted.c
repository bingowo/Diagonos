#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    unsigned long long a[75];
    int n;
    scanf("%d",&n);
    a[0]=0;
    a[1]=1;
    a[2]=1;
    for (int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        for (int j=3;j<=k;j++)
            a[j]=a[j-1]+a[j-2]+a[j-3];
        printf("case #%d:\n",i);
        printf("%llu\n",a[k]);
    }

    return 0;
}