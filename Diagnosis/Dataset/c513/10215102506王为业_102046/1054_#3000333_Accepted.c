//string\1054.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


int isEND=FALSE;
char* words[500];
char tembuf[1005];
int getword()
{
    char c;
    int wordlen=0;
    while((c=getchar())==' ');
    while(c!=EOF&&c!=' '&&c!='\n'){
        tembuf[wordlen++]=c;
        c=getchar();
    }
    if(c==EOF||c=='\n'){
        isEND=TRUE;
    }
    return wordlen;
}

void sum_up_tem_line(int M,int NOWlinelen,int wordnum)
{
    int extra_spaces=M-NOWlinelen;
    int common_spaces=1;
    if(extra_spaces>=(wordnum-1)){
        common_spaces+=extra_spaces/(wordnum-1);
        extra_spaces%=(wordnum-1);
    }
    for(int i=0;i<wordnum-1;++i){
        printf("%s",words[i]);
        for(int k=0;k<common_spaces;++k){
            putchar(' ');
        }
        if(i>=wordnum-extra_spaces-1){
        putchar(' ');
        }
        free(words[i]);
        words[i]=NULL;
    }
    printf("%s\n",words[wordnum-1]);
    free(words[wordnum-1]);
    words[wordnum-1]=NULL;
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
        int M;
        scanf("%d",&M);
        getchar();
        int NOWlinelen=0;
        int twordlen=0;
        int wordnum=0;
        //Load first word---------------------
        twordlen=getword();
        words[wordnum]=malloc(twordlen+1);
        for(int i=0;i<twordlen;++i){
            words[wordnum][i]=tembuf[i];
        }
        words[wordnum][twordlen]='\0';
        ++wordnum;
        NOWlinelen+=twordlen;
        //-------------------------------------
        while(!isEND){//when the word received has contents, go on
            twordlen=getword();
            if(twordlen+1+NOWlinelen<=M){
                words[wordnum]=(char*)malloc((twordlen+1)*sizeof(words[0]));
                for(int i=0;i<twordlen;++i){
                    words[wordnum][i]=tembuf[i];
                }
                words[wordnum][twordlen]='\0';
                ++wordnum;
                NOWlinelen+=twordlen+1;
            }else{
                sum_up_tem_line(M,NOWlinelen,wordnum);
                wordnum=0;
                NOWlinelen=0;
                //Load first word---------------------
                if(twordlen!=0)
                    words[wordnum]=malloc(twordlen+1);
                for(int i=0;i<twordlen;++i){
                    words[wordnum][i]=tembuf[i];
                }
                words[wordnum][twordlen]='\0';
                ++wordnum;
                NOWlinelen+=twordlen;
            }
        }
        for(int i=0;i<wordnum-1;++i){
            printf("%s ",words[i]);
        }
        printf("%s\n",words[wordnum-1]);
        isEND=FALSE;
    }

}

