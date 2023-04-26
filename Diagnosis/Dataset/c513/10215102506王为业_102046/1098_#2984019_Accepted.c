//others\1098.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

char input[110];
int insize;
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
        int state[5]={-1,-1,-1,-1,-1};
        int num[5]={0};
        printf("case #%d:\n",iT);
        scanf("%s",input);
        insize=strlen(input);
        for(int i=0;i<insize;++i){
            if(input[i]!='!'){
                if(input[i]=='R'){
                    state[0]=i%4;
                }else if(input[i]=='B'){
                    state[1]=i%4;
                }else if(input[i]=='Y'){
                    state[2]=i%4;
                }else if(input[i]=='G'){
                    state[3]=i%4;
                }
            }
        }

        //indicate floor
        for(int i=0;i<4;++i){
            if(state[i]==-1){
                state[i]=0;
                int tem=0;
                for(int k=0;k<4;++k){
                    tem+=state[k];
                }
                state[i]=6-tem;
            }
        }
        //state[i] stores where their positions are
        //state[0] refers to 'R'
        for(int i=0;i<insize;++i){
            if(input[i]=='!'){
                ++num[i%4];
            }
        }
        //using num[state[0]] to read R
        for(int i=0;i<3;++i){
            printf("%d ",num[state[i]]);
        }
        printf("%d\n",num[state[3]]);
    }
}

