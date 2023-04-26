#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long rep(int n)
{
    long long arr[100];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    arr[4]=8;
    for(int i=5;i<n+1;i++)
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4];
    return arr[n];

}

int main()
{
    int T;  scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        printf("%lld\n",rep(n));
    }
    return 0;
}