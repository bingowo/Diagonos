//sort\1097.c

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

struct ch{
    char ch;
    int height,pos;
};

typedef struct ch single;
#define ARRLEN 105
single word[ARRLEN];
int wordlen=0;

int getarr()
{
    memset(word,0,ARRLEN*sizeof(word[0]));
    wordlen=0;
    char c;
    int nowheight=0;
    int nowpos=0;
    char bc=0;
    while((c=getchar())!='\n'&&c!=EOF){

        if(c<bc)
            --nowheight;
        else if(c>bc)
            ++nowheight;
        word[wordlen].height=nowheight;
        word[wordlen].pos=nowpos;
        bc=word[wordlen].ch=c;
        ++nowpos;
        ++wordlen;
    }

    return c;
}

int cmp(single*x,single*y)
{
    if(x->height == y->height){
        return x->pos > y->pos? 1:-1;
    }else{
        return x->height >y->height ? -1:1;
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int state=TRUE;
    while(state){
        if(getarr()==EOF)
            state=FALSE;
        qsort(word,wordlen,sizeof(word[0]),cmp);
        single* p_begin=word;
        single* p_end=word+wordlen;
        while(p_begin!=p_end){
            single* end_surf=p_begin+1;//part of getting same floor
            while(end_surf!=p_end&&end_surf->height==p_begin->height){
                ++end_surf;
            }
            int bpos=-1;
            while(p_begin!=end_surf){//output module
                for(int ispace=0;ispace< p_begin->pos - bpos -1;++ispace){
                    putchar(' ');
                }
                bpos=p_begin->pos;
                putchar(p_begin->ch);
                ++p_begin;
            }
            putchar('\n');
        }
    }
}

