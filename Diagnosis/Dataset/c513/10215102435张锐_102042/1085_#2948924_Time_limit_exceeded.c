#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned long long a,b;
    while(scanf("%llu%llu",&a,&b))
    {
        printf("%lld\n",a-b);
    }
    return 0;
}