//string\1048.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

char *words[260];
int num_words;
char temword[510];
int temlen;
char getword()
{
    char c;
    temlen=0;
    memset(temword,0,510*sizeof(char));
    while((c=getchar())=='!'||c==','||c=='.'||c=='?'||c==' ');
    while(c!=EOF&&c!='\n'&&c!=','&&c!='.'&&c!='!'&&c!='?'&&c!=' '){
        temword[temlen++]=c;
        c=getchar();
    }
    temword[temlen]='\0';
    return c;
}
int notsame()
{
    for(int i=0;i<num_words;++i){
        if(strcmp(words[i],temword)==0)
            return FALSE;
    }
    return TRUE;
}
int cmp(char**x,char**y)
{
    return strcmp(*x,*y);
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
        num_words=0;
        char temc;
        while((temc=getword())!='\n'&&temc!=EOF){
            if(notsame()){
                words[num_words++]=(char*)malloc(temlen*sizeof(char));
                strcpy(words[num_words-1],temword);
            }
        }//sometimes,there is no problem,but debugger may think that there is
        qsort(words,num_words,sizeof(words[0]),cmp);
        for(int iword=0;iword<num_words-1;++iword){
            printf("%s ",words[iword]);
        }
        printf("%s\n",words[num_words-1]);
        while(num_words--){
            free(words[num_words]);
        }
        memset(words,0,260*sizeof(words[0]));
    }
}
