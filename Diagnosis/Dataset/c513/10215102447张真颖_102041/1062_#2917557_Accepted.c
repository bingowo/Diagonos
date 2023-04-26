#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0;
        long long arr[51]={0};
        arr[1]=1;
        arr[2]=2;
        arr[3]=4;
        arr[4]=8;
        scanf("%d",&n);
        for(int i=5;i<=n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
        }
        printf("case #%d:\n%lld\n",i,arr[n]);
    }
    return 0;
}