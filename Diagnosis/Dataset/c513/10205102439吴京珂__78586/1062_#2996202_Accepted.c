#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        //int ans=0;
        long long int a[55]={0};
        a[1]=1;a[2]=2;a[3]=4;a[4]=8;
        for(int j=5;j<=n;j++)
        {
            a[j]=a[j-1]+a[j-2]+a[j-3]+a[j-4];
        }

        printf("case #%d:\n",i);
        printf("%lld\n",a[n]);
    }

    return 0;
}



