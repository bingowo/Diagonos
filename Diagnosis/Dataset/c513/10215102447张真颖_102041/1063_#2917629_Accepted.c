#include <stdio.h>
#include <stdlib.h>

long long count(long long x,long long y)
{
    if(x%y==0) return 4*y*(x/y);
    else
        return 4*y*(x/y)+count(y,x%y);
}

int main()
{
    long long x,y;
    scanf("%ld%ld",&x,&y);
    printf("%ld",count(x,y));
    return 0;
}

