#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long int ulli;

ulli max(ulli a,ulli b){return a>b?a:b;}

ulli min(ulli a,ulli b){return a>b?b:a;}

int main()
{
    ulli x,y;
    scanf("%llu%llu",&x,&y);
    ulli len=max(x,y),wid=min(x,y);
    ulli energy=0;
    if(len%wid==0){
        energy=4*wid*(len/wid);
    }
    else{
        while(x*y>0){
            energy+=4*wid;
            x=len-wid;
            y=wid;
            len=max(x,y),wid=min(x,y);
        }
    }
    printf("%llu",energy);


}


