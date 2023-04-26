//digsys\1012.c
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

typedef struct complex compl;
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    LL a,b;
    int positive_a=TRUE;
    char c;
    if((c=getchar())=='-')positive_a=FALSE;
    ungetc(c,stdin);
    if(scanf("%lld",&a)!=1){//scanf !=1 is useful
        if(!positive_a){
            a=0;b=-1;
        }else{
            a=0;b=1;
        }
    }else{
        char c;
        if((c=getchar())=='i'){
            b=a;a=0;
        }else if(c=='\n'){
            b=0;
        }else{
            int positive_b=TRUE;
            if(c=='-')
                positive_b=FALSE;
            if(scanf("%lld",&b)!=1){
                if(positive_b)
                    b=1;
                else
                    b=-1;
            }else{
                if(!positive_b)
                    b=-b;
            }
        }
    }
    if(a==0&&b==0){
        printf("0");
        return 0;
    }
    char bin[500];
    int binlen=0;
    long long qr,qi;
    while(a!=0||b!=0){
        if(a&1 ^ b&1){
            qr=(b-a+1)/2;
            qi=(1-a-b)/2;
            bin[binlen++]='1';
        }else{
            qr=(b-a)/2;
            qi=(-a-b)/2;
            bin[binlen++]='0';
        }
        a=qr;b=qi;
    }
    for(int i=binlen-1;i>=0;--i){
        putchar(bin[i]);
    }
}
