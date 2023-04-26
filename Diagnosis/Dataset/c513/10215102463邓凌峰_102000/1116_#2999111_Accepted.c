#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 550
#define BigNUm 10007

typedef long long lli;

lli llabs(lli x){ return x>0?x:-x;}

lli count(lli distance){
    lli cnt=0;
    while(distance>0){
        cnt++;
        distance/=2;
    }
    return cnt;
}



int main(){
    lli x,y;scanf("%lld%lld",&x,&y);
    lli distance=llabs(x)+llabs(y);
    if(distance%2==0 && distance!=0) printf("-1");
    else printf("%lld",count(distance));

    return 0;

}
