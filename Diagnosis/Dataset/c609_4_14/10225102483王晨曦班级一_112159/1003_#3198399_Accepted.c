#include <stdio.h>
#include <stdlib.h>
#define N 10000

main(void)
{
    long long int n,a[N];
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);

    for(int k=0;k<n;k++)
    {
        int cnt=0;
        long long int c[N];
        if(a[k]==0) printf("0");
        else
            {
                while(a[k]>0)
                {
                    c[cnt]=a[k]%2333;
                    a[k]=a[k]/2333;
                    cnt++;
                }
                for(int i=(cnt-1);i>=0;i--) printf("%lld ",c[i]);
            }

        printf("\n");
    }
    return 0;
}