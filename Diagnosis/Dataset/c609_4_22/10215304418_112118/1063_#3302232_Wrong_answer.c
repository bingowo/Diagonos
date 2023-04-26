#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    long long a[50]={0};
    a[0]=1;
    for (int i=1;i<=50;i++){
        if (i-1>=0) a[i]+=a[i-1];
        if (i-2>=0) a[i]+=a[i-2];
        if (i-3>=0) a[i]+=a[i-3];
        if (i-4>=0) a[i]+=a[i-4];
    }
    for (int i=1;i<=t;i++){
        int x;
        scanf("%d",&x);
        printf("case #%d:\n",i-1);
        printf("%lld\n",a[x]);
    }
    return 0;
}
