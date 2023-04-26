#include<stdio.h>

int main()
{
    long long arr[21];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 7;
    for(int i = 4; i < 21; i++)
    {
        arr[i] = arr[i - 1] * 2 - arr[i - 2] + arr[i - 3];
    }
    
    int n;
    
    while(scanf("%d", &n) && n != -1)
    {
        printf("%lld", arr[n]);
    }
    return 0;
}
