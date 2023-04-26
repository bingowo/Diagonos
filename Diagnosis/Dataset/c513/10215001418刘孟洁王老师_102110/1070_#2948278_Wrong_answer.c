#include <stdio.h>
#include <stdlib.h>
#include<math.h>

long long int num(long long int n)
{
    if(n < 3)return pow(2,n);
    else return 2*num(n-1)-num(n-2)+num(n-3);
}

int main()
{
    long long int n;
    while(1)
    {
        scanf("%lld",&n);
        if(n == -1)break;
        printf("%lld\n",num(n));
    }
    printf("%lld\n",pow(2,17));
    return 0;
}
