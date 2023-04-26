#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000

typedef long long lli;

lli llabs(lli x){
    return x>0?x:-1*x;
}

lli distance(lli x,lli y){
    return llabs(x)+llabs(y);
}

void move(int now,int cnt,int step,lli x,lli y,char *way){

}

int main() {
    lli x,y;scanf("%lld%lld",&x,&y);
    lli dis=distance(x,y);

    if(dis%2==0 &&dis!=0) printf("-1");
    else{
        int cnt=0;
        while(dis){
        cnt++;
        dis/=2;
        }

    }



    return 0;
}
