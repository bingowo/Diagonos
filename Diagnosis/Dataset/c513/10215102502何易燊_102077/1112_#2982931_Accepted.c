#include <stdio.h>

long long arr[1001] = {1};

int main()
{
    for (int i=4;i>=1;i--)
        for (int j=i;j<=1001;j++) arr[j] += arr[j-i];
    int n; scanf("%d",&n);
    while (n--)
    {
        int m; scanf("%d",&m);
        printf("%lld\n",arr[m]);
    }
    return 0;
}