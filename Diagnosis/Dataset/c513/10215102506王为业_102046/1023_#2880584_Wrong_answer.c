//sort\1022.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define LOCAL
#define TRUE 1
#define FALSE 0
struct str{
    char word[33];
    int num;//if(num==-1) meaning no num;
};
typedef struct str wstring;
wstring strlist[110];

int strnumcmp(wstring*x,wstring*y)
{
    if(x->num==y->num){
        return strcmp(x->word,y->word);
    }else{
        return x->num>y->num?1:-1;
    }
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n=0;
    while(scanf("%s",&strlist[n].word)!=EOF)
        ++n;//avoid wrongly high n
    char *tEMwORDp;
    char temnum[11];
    int temnumPOS=0;
    for(int in=0;in<n;++in){
        tEMwORDp=strlist[in].word;
        temnumPOS=0;
        while(*tEMwORDp){
            if('0'<=*tEMwORDp&&*tEMwORDp<='9'){
                temnum[temnumPOS++]=*tEMwORDp;
            }
            ++tEMwORDp;
        }
        if(temnumPOS==0)
            strlist[in].num=-1;
        else{
            temnum[temnumPOS]='\0';
            strlist[in].num=atoi(temnum);
        }
    }
    qsort(strlist,n,sizeof(strlist[0]),strnumcmp);
    for(int in=0;in<n-1;++in){
        printf("%s ",strlist[in].word);
    }printf("%s",strlist[n-1].word);
}
