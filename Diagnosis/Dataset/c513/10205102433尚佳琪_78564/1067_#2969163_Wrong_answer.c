#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        unsigned long long  a[75];
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(int i=3;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-2]+a[i-3];

        }
        printf("%llu\n",a[n]);
    }
    return 0;
}
