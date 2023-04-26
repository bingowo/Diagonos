#include <stdio.h>
#include <stdlib.h>

long long mod(long long a)
{
    long long rem=a%(-2);
    long long res=a/(-2);

    if (rem<0){rem+=2;res+=1;}

    if(res)mod(res);

    printf("%lld",rem);

    return 0;
}

int main()
{
    long long n;scanf("%lld",&n);
    mod(n);
    printf("\n");
    return 0;
}
