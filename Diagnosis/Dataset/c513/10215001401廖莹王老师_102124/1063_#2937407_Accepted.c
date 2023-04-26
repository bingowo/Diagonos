#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x=0,y=0,y1=0;
    long long tl=0;
    scanf("%lld %lld",&x,&y);
    if(x>y){y1=x;x=y;y=y1;}
    long long i=0,x1=0;
        while(x!=0)
        {
            i=y/x;
            tl=tl+4*x*i;
            x1=x;
            x=y%x1;y=x1;
        }
    printf("%lld\n",tl);
    return 0;
}
