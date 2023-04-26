//string\1042.c
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

char difS[20];
int difSlen;
int can_inp(char c)
{
    for(int i=0;i<difSlen;++i){
        if(c==difS[i])
            return FALSE;
    }
    return TRUE;
}
int scmp(char *x,char*y)
{
    return *x-*y;
}

char temstr[20];
int temhilen;

int nowlen;

void prCOMB(int difpos)
{
    if(nowlen==temhilen){
        for(int i=0;i<temhilen;++i){
            putchar(temstr[i]);
        }
        putchar('\n');
        return;
    }else{
        for(int k=difpos;k<=difSlen-temhilen+nowlen;++k){
            temstr[nowlen++]=difS[k];
            prCOMB(k+1);
            --nowlen;
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
        char c;
        difSlen=0;
        while((c=getchar())!='\n'&&c!=EOF){
            if(can_inp(c))
                difS[difSlen++]=c;
        }
        qsort(difS,difSlen,sizeof(difS[0]),scmp);
        nowlen=0;
        temhilen==1;
        while(temhilen<=difSlen){
            prCOMB(0);
            ++temhilen;
        }
    }
}
