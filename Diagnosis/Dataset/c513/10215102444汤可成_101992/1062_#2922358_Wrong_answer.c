#include <stdio.h>
#include <stdlib.h>

long long int arr[50] = {1, 2, 4, 8};

long long int f(int n)
{
    if(arr[n-1]!=0) return arr[n-1];
    else
    {
        long long num = f(n-4)+f(n-3)+f(n-2)+f(n-1)+f(1)+f(2)+f(3)+f(4);
        arr[n-1] = num;
        return num;
    }
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d", &T);
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n",i);
        int n = 0;
        scanf("%d", &n);
        printf("%lld\n", f(n));
    }
    return 0;
}
