//digsys\1011.c
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
unsigned char HEXtoDEC(char hex)
{
    if(hex>='0'&&hex<='9')
        return hex-'0';
    else
        return hex-'A'+10;
}

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
    unsigned char binary[500];//0,1存储
    char hex[200];
    getchar();
    getchar();
    scanf("%s",hex);
    int hexlen=strlen(hex);
    int binarylen=0;
    if(hexlen==1&&hex[0]=='0'){
        printf("0");
        return 0;
    }
    int tem=HEXtoDEC(hex[0]);
    int temlen=4;
    while((1<<temlen)&tem==0)--temlen;
    while(temlen>=0){
        binary[binarylen++]=((1<<temlen)&tem)>>temlen;
        --temlen;
    }
    for(int ihex=1;ihex<hexlen;++ihex){
        tem=HEXtoDEC(hex[ihex]);
        for(int i=3;i>=0;--i){
            binary[binarylen++]=((1<<i)&tem)>>i;
        }
    }
    compl result={0,0};
    for(int i=0;i<binarylen;++i){
        LL tr=result.r,ti=result.i;
        if(binary[i]){
            result.r=1LL-tr-ti;
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
