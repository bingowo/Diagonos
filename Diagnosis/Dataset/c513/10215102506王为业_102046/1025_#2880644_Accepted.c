//sort\1025.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

//#define LOCAL
#define TRUE 1
#define FALSE 0
struct words{
    char str[22];
    int kinds;
}wordlist[102];
typedef struct words word;
int haveBEEN[27];
int calkinds(char *str)
{
    int ret=0;
    memset(haveBEEN,0,27*sizeof(haveBEEN[0]));
    while(*str){
        if(!haveBEEN[*str-'A']){
            haveBEEN[*str-'A']=1;
            ++ret;
        }
        ++str;
    }
    return ret;
}
int cmp(word*x,word*y)
{
    if(x->kinds==y->kinds){
        return strcmp(x->str,y->str);
    }else{
        return x->kinds>y->kinds?-1:1;
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
    for(int iT=0;iT<T;++iT){
        int n;
        printf("case #%d:\n",iT);
        scanf("%d",&n);
        for(int in=0;in<n;++in){
            scanf("%s",wordlist[in].str);
            wordlist[in].kinds=calkinds(wordlist[in].str);
        }
        qsort(wordlist,n,sizeof(wordlist[0]),cmp);
        for(int in=0;in<n;++in)
            printf("%s\n",wordlist[in].str);
    }
}
