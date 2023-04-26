#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

int main()
{
    long long arr[MAX+3] = {0};
    int k,n;
    scanf("%d%d",&k,&n);

    arr[1] = 0, arr[2] = 1;
    for(int i = 3; i <= k+1; i++)
        arr[i] = pow(2,i-3);

    for(int i = k+2; i <= n; i++)
        arr[i] = 2*arr[i-1] - arr[i-k-1];


    printf("%lld",arr[n]);

    return 0;
}
