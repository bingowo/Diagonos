#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int n;
        scanf("%d",&n);
        long long int a[75]= {0};
        a[0]=0;a[1]=1;a[2]=1;
        for(int j=3; j<=n; j++)
        {
            a[j]=a[j-1]+a[j-2]+a[j-3];
        }
        printf("case #%d:\n%lld\n",i,a[n]);
    }
    return 0;
}



