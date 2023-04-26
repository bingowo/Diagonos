#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0; z<T; z++)
    {
        int m, n;
        unsigned long long ans=1;
        scanf("%d%d",&m,&n);
        n=n>m/2?(m-n):n;
        for(int i=0; i<n; i++)
            ans*=(m-i);
        for(int i=1; i<=n; i++)
            ans/=i;
        printf("case #%d:\n",z);
        printf("%lld\n",ans);
    }

}
