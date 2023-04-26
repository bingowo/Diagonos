//greedy\1063.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    ULL x,y;
    ULL total=0;
    scanf("%llu %llu",&x,&y);
    while(x!=y){
        if(x>y){
            ULL tem=x;
            x=y;
            y=tem;
        }//make sure x<y
        ULL times=2;
        while(x*times<y-x)++times;
        --times;
        total+=4*x*times;
        y-=x*times;
    }
    total+=4*x;
    printf("%llu",total);

}
