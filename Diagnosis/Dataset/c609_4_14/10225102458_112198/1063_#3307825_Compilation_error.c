#include <stdio.h>
#include <stdlib.h>
long long int a[51];
int main()
{
    int n;
    scanf("%d",&n);
    a[1]=1;a[2]=2;a[3]=4;a[4]=8;
    for(int i=0;i<n;i++){
        memset
        int m;
        scanf("%d",&m);
        for(int i=5;i<=m;i++){
            a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",a[m]);
    }
    return 0;
}
