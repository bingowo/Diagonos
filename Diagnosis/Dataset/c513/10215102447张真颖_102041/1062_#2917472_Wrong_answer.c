#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n=0;
        long long arr[50]={0};
        arr[0]=1;
        arr[1]=2;
        scanf("%d",&n);
        for(int i=2;i<n;i++)
        {
            arr[i]=arr[i-1]+arr[i-2];
        }
        printf("case #%d:\n%lld\n",i,arr[n-1]);
    }
    return 0;
}