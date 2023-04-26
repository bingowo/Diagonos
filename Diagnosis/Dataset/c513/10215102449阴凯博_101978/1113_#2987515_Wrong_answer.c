#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    long long arr[120]={0};
    arr[0]=0; arr[1]=1;
    for (int i=2;i<n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            if (i-j>=0)
                arr[i]+=arr[i-j];
        }

    }
    printf("%lld\n",arr[n-1]);
    return 0;
}
