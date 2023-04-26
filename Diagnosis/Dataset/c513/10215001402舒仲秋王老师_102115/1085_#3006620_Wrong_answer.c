#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;;)
    {
        long long int a,b;
        if(scanf("%lld %lld",&a,&b)==EOF) break;
        printf("%lld\n",a-b);
    }
    return 0;
}
