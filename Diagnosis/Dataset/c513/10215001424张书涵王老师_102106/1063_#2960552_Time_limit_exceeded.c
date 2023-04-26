#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int x,y;
    scanf("%lld %lld",&x,&y);
    long long int len,wid,side;
    long long int c=0;
    for(len=y,wid=x;len!=wid;)
    {
        side=(len>wid)?wid:len;
        c=c+4*side;
        if(len>wid)
            len=len-wid;
        else
            wid=wid-len;
    }
    c=c+4*len;
    printf("%lld",c);
}