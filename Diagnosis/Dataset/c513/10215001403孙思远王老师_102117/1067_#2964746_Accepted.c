#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    int i;
    long long int a[74];
    a[0]=0,a[1]=1,a[2]=1;
    for(i=3;i<74;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int x;
        scanf("%d",&x);
        printf("%lld\n",a[x]);
    }
    return 0;
}
