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
        char c[5]={0};
        int num[5]={0};
        printf("case #%d:\n",iT);
        scanf("%s",input);
        insize=strlen(input);
        int tem;
        for(int i=0;i<insize;++i){
            if(input[i]!='!'){
                c[i%4]=input[i];
            }
        }
        for(int i=0;i<insize;++i){
            if(input[i]=='!'){
                ++num[i%4];
            }
        }
        for(int i=0;i<4;++i){
            if(c[i]=='R')
                printf("%d ",num[i]);
        }
        for(int i=0;i<4;++i){
            if(c[i]=='B')
                printf("%d ",num[i]);
        }
        for(int i=0;i<4;++i){
            if(c[i]=='Y')
                printf("%d ",num[i]);
        }
        for(int i=0;i<4;++i){
            if(c[i]=='G')
                printf("%d\n",num[i]);
        }
    }
}

