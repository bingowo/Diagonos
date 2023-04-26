#include <stdio.h>
#include <stdlib.h>

int main()

{
    long long int a[10000];
    int b[10000];
    int t,n;
    scanf("%d",&t);
    for (int i=0; i<t; i++)
    {
        scanf("%d",&n);
        for (int j=0; j<n; j++)
        {
            scanf("%lld",&a[j]);
            int m=a[j];
            b[j]=0;
            for (int k=0; k<64; k++)
                b[j]=b[j]+(m>>1&1);
        }

        for (int j=0; j<n-1;j++)
        {
            int m=j;
            for (int k=j+1;k<n;k++)
                if (b[m]<b[k]||(b[m]==b[k]&&a[m]>a[k])) m=k;
            int u=b[j];b[j]=b[m];b[m]=u;
            long long int u1=a[j];a[j]=a[m];a[m]=u1;
        }

        printf("case #%d:\n",i);
        for (int j=0;j<n-1;j++)
        {
            printf("%lld ",a[j]);
        }
        printf("%lld\n",a[n-1]);

    }

    return 0;
}
