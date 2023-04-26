#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 110

typedef long long int lli;

lli absll(lli x){ return x<0?-x:x;}



int main()
{
    lli x,y;
    scanf("%lld %lld",&x,&y);
    lli dis=absll(x)+absll(y);
    if (dis==0) {
        printf("0");
    }
    else if(dis%2==0){
        printf("-1");
    }
    else{
        lli ret=0;
        while (dis>0) {
            ret++;
            dis=dis>>1;
        }
        printf("%lld",ret);
    }
    return 0;
}
