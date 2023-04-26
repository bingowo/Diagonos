#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    unsigned long long int x,y;
    scanf("%llu %llu",&x,&y);
    unsigned long long int ans=0;
    while(x!=y)
    {
        if(x>y)
        {
            x=x-y;
            ans+=y;
        }
        else
        {
            y=y-x;
            ans+=x;
        }
    }
    if(x==y) ans+=x;
    printf("%llu\n",ans*4);

    return 0;
}



