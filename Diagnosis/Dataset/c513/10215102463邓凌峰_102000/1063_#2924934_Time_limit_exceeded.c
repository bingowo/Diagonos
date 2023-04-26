#include <stdio.h>
#include <stdlib.h>


typedef long long int lli;

lli max(lli a,lli b){return a>b?a:b;}

lli min(lli a,lli b){return a>b?b:a;}

int main()
{
    lli x,y;
    scanf("%lld%lld",&x,&y);
    lli len=max(x,y),wid=min(x,y);
    lli energy=0;
    while(x*y>0){
        energy+=4*wid;
        x=len-wid;
        y=wid;
        len=max(x,y),wid=min(x,y);
    }
    printf("%lld",energy);


}

