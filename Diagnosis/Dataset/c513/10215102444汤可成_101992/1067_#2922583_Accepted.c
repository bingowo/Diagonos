#include <stdio.h>
#include <stdlib.h>

long long int arr[74] = {0,1,1,2};

long long int tribo(int n)
{
    if(n == 0 || arr[n]!=0) return arr[n];
    else
    {
        long long int num = tribo(n-1)+tribo(n-2)+tribo(n-3);
        arr[n] = num;
        return num;
    }
}

int main()
{
    int T = 0;
    int i = 0;
    scanf("%d",&T);
    for(i = 0; i<T; i++)
    {
        printf("case #%d:\n",i);
        int n = 0;
        scanf("%d",&n);
        printf("%lld\n", tribo(n));
    }
    return 0;
}
