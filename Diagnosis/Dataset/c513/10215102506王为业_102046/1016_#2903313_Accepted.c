//digsys\1016.c

//why i&1 fails
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
#define NUMSIZE 60
unsigned char num[NUMSIZE];

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int R;
    int N;
    scanf("%d %d",&N,&R);
    int numlen=0;
    int absR=abs(R);
    int absN=abs(N);
    while(absN!=0){
        num[numlen++]=absN%absR;
        absN/=absR;
    }
    R=-R;
    if(N<0){
        N=-N;
        for(int i=0;i<NUMSIZE-2;++i){
            if(i%2==0){
                if(num[i]!=0){
                ++num[i+1];
                num[i]=R-num[i];//may have problems;
                }
            }else{
                if(num[i]>=R){
                    num[i+1]+=num[i]/R;
                    num[i]%=R;
                }
            }
        }
    }else if(N>0){
        for(int i=0;i<NUMSIZE-2;++i){
            if(i%2){//diff
                if(num[i]!=0){
                ++num[i+1];
                num[i]=R-num[i];//may have problems;
                }
            }else{
                if(num[i]>=R){
                    num[i+1]+=num[i]/R;
                    num[i]%=R;
                }
            }
        }
    }else{
        putchar('0');
        return 0;
    }
    numlen=NUMSIZE-1;
    while(num[numlen]==0)--numlen;
    for(int i=numlen;i>=0;--i){
        printf("%c",num[i]<10?num[i]+'0':num[i]-10+'A');
    }
}
