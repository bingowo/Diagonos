//sort\1036.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
struct complex{
    long long r,i;
};
void pr_i(long long i)
{
    if(i==1)
        printf("i");
    else if(i==-1)
        printf("-i");
    else
        printf("%lldi",i);
}
typedef struct complex compl;
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    LL innum;
    scanf("%llx",&innum);
    int top=8*sizeof(innum)-2;//avoidnegative index
    if(innum==0){
        printf("0");
        return 0;
    }//why to add >>
    while(((1<<top)&innum)>>top==0)--top;//bit calc <<,then>>
    compl result={0,0};
    for(int i=top;i>=0;--i){
        LL tr=result.r,ti=result.i;
        if(((1<<i)&innum)>>i){
            result.r=1-tr-ti;
        }else{
            result.r=-tr-ti;
        }
        result.i=tr-ti;
    }
    if(result.r){
        if(result.i>0){
            printf("%lld+",result.r);
            pr_i(result.i);
        }else if(result.i<0){
            printf("%lld",result.r);
            pr_i(result.i);
        }else{
            printf("%lld",result.r);
        }
    }else{
        pr_i(result.i);
    }

}
