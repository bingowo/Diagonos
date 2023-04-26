//digsys\1080.c
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

unsigned char n_dec[110];
int dlen=0;
unsigned char t_dec[110];
int tlen=0;
unsigned char n_bin[400];
int blen=0;
void highac_add()
{
    int highlen=tlen>dlen?tlen:dlen;
    for(int i=0;i<highlen-1;++i){
        n_dec[i]+=t_dec[i];
        if(n_dec[i]>=10){
            n_dec[i+1]+=n_dec[i]/10;
            n_dec[i]%=10;
        }
    }
    n_dec[highlen-1]+=t_dec[highlen-1];
    if(n_dec[highlen-1]>=10){
        n_dec[highlen]=n_dec[highlen-1]/10;
        n_dec[highlen-1]%=10;
        ++highlen;
    }
    dlen=highlen;
}
void highac_div_two()//to dlen and update value
{
    for(int i=dlen-1;i>=0;--i){
        if(n_dec[i]&1){
            --n_dec[i];
            n_dec[i-1]+=10;
        }
        n_dec[i]/=2;
    }
    while(dlen>0&&n_dec[dlen-1]==0)--dlen;
}
void highac_mul_two()
{
    for(int i=0;i<tlen;++i){
        t_dec[i]<<=1;
    }
    for(int i=0;i<tlen-1;++i){
        if(t_dec[i]>=10){
            t_dec[i+1]+=t_dec[i]/10;
            t_dec[i]%=10;
        }
    }
    if(t_dec[tlen-1]>10){
        t_dec[tlen]+=t_dec[tlen-1]/10;
        t_dec[tlen-1]%=10;
        ++tlen;
    }
}

void turntobin()
{
    while(dlen!=0){
        if(n_dec[0]&1){
            --n_dec[0];
            n_bin[blen++]=1;
        }else{
            n_bin[blen++]=0;
        }
        highac_div_two();//to dlen and update value
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
        blen=dlen=0;
        memset(n_bin,0,400*sizeof(n_bin[0]));
        memset(n_dec,0,110*sizeof(n_dec[0]));
        memset(t_dec,0,110*sizeof(t_dec[0]));
        printf("case #%d:\n",iT);
        char c;
        while((c=getchar())!='\n'&&c!=EOF){
            n_dec[dlen++]=c-'0';
        }
        if(dlen==1&&n_dec[0]==0){
            printf("0\n");
            continue;
        }
        for(int i=0,j=dlen-1;i<j;++i,--j){//swap input
            unsigned char tem=n_dec[i];
            n_dec[i]=n_dec[j];
            n_dec[j]=tem;
        }//0->dlen-1 arr
        turntobin();
        for(int i=0,j=blen-1;i<j;++i,--j){//swap binary
            unsigned char tem=n_bin[i];
            n_bin[i]=n_bin[j];
            n_bin[j]=tem;
        }
        while(blen>0&&n_bin[blen-1]==0)--blen;//update blen
        memset(n_dec,0,110*sizeof(n_dec[0]));
        t_dec[0]=1;
        tlen=1;
        for(int i=0;i<blen;++i){
            if(n_bin[i]){
                highac_add();//n_dec +=t_dec
            }
            highac_mul_two();
        }
        for(int i=dlen-1;i>=0;--i){
            printf("%d",n_dec[i]);
        }putchar('\n');
    }
}
