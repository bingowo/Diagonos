#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;;)
    {
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        printf("%lld",a-b);
    }
    return 0;
}
