#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int res=0;
    while(x!=y)
    {
        if(x<y)
        {
            long long int a;
            a=x;x=y;y=a;
        }
        res=res+4*y;
        long long int b=x-y;
        x=x-y;
    }
    res=res+4*y;
    printf("%lld\n",res);
    return 0;
}
