#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int a[74];
    a[0]=0;
    a[1]=1; a[2]=1;
    for(int i=3;i<74;i++)
        a[i]=a[i-1]+a[i-2]+a[i-3];
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
