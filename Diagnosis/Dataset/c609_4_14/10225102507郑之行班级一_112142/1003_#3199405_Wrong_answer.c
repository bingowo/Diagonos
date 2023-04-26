#include <stdio.h>
#include <stdlib.h>

void mod(long long a)
{
    if(a)
    {
        mod(a/2333);
        printf("%lld ",a%2333);
    }
}

int main()
{
    int T;scanf("%d",&T);
    long long a;
    for (int i=0;i<T;i++)
    {
        scanf("%lld",&a);
        mod(a);
        printf("\n");
    }
    return 0;
}
