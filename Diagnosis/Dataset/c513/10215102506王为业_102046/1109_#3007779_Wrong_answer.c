//string\1109.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

void make_pow(int coe,int pow)
{
    coe=abs(coe);
    if(coe!=0){
        if(coe!=1){
            printf("%d",coe);
        }
        putchar('x');
        if(pow!=1){
            printf("^%d",pow);
        }
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int PUREZERO=TRUE;
        int nownum;
        make_pow(nownum,8);
        for(int ipow=8;ipow>=1;--ipow){
            scanf("%d",&nownum);
            if(nownum!=0){
                if(nownum<0)
                    putchar('-');
                else if(!PUREZERO)
                    putchar('+');
                make_pow(nownum,ipow);
                PUREZERO=FALSE;
            }
        }
        scanf("%d",&nownum);
        if(nownum!=0||PUREZERO){
            if(PUREZERO&&nownum>0)
                putchar('+');
            printf("%d",nownum);
        }
        putchar('\n');
    }
}