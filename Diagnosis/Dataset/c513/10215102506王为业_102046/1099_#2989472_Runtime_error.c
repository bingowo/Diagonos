//simu\1099.c

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

struct str_trie
{
    char c;
    struct str_trie*point;
    struct str_trie*under;
};
typedef struct str_trie trie;

trie root={0,NULL,NULL};

void insert(char* str,int slen,char ret)
{
    trie* t_node=&root;
    for(int i=0;i<slen;++i){
        if(str[i]=='-'){
            if(t_node->under==NULL){
                t_node->under=(trie*)malloc(sizeof(trie));
                memset(t_node->under,0,sizeof(trie));
            }
            t_node=t_node->under;
        }else if(str[i]=='.'){
            if(t_node->point==NULL){
                t_node->point=(trie*)malloc(sizeof(trie));
                memset(t_node->point,0,sizeof(trie));
            }
            t_node=t_node->point;
        }else{
            printf("ERROR:_.\n");
        }
    }
    t_node->c=ret;
}

char search(char* str,int slen)
{
    trie*tnode=&root;
    for(int i=0;i<slen;++i){
        if(str[i]=='-'){
            tnode=tnode->under;
        }else if(str[i]=='.'){
            tnode=tnode->point;
        }
        if(tnode==NULL){
            printf("FAILURE");
        }
    }
    return tnode->c;
}

void del_root(trie* node)
{
    if(node->point!=NULL){
        del_root(node->point);
        free(node->point);
    }
    if(node->under!=NULL){
        del_root(node->under);
        free(node->under);
    }
}

void pre_deal()
{
    char*alphabet=".-/-.../-.-./-.././..-./--./..../../.---/-.-/.-../--/-./---/.--./--.-/.-./.../-/..-/...-/.--/-..-/-.--/--../";
    char*number="-----/.----/..---/...--/....-/...../-..../--.../---../----./";
    char*cp=alphabet;
    char temword[7];
    int temlen=0;
    for(char ic='A';ic<='Z';++ic){
        while(*cp!='/'){
            temword[temlen++]=*cp++;
        }
        ++cp;//getnext;
        temword[temlen]='\0';
        insert(temword,temlen,ic);
        temlen=0;
    }
    cp=number;
    for(int ic='0';ic<='9';++ic){
        while(*cp!='/'){
            temword[temlen++]=*cp++;
        }
        ++cp;//getnext;
        temword[temlen]='\0';
        insert(temword,temlen,ic);
        temlen=0;
    }
}
char str[1010];
int slen;
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    pre_deal();
    int T;
    char ans[125];
    int anslen;
    scanf("%d",&T);
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        anslen=0;
        scanf("%s",str);
        slen=strlen(str);
        char temarr[10];
        int temlen=0;
        for(int i=0;i<slen;){//i++ is left
            temlen=0;
            while(str[i]!='\0'&&str[i]!='/'){
                temarr[temlen++]=str[i++];
            }
            temarr[temlen]='\0';
            if(str[i]=='\0'){
                ans[anslen++]=search(temarr,temlen);
            }else if(str[i]=='/'){
                ans[anslen++]=search(temarr,temlen);
                int slashlen=1;
                while(str[i+slashlen]=='/')
                    ++slashlen;
                switch(slashlen){
            case 1:
                break;
            case 3:
                ans[anslen++]=' ';
                break;
            case 5:
                ans[anslen++]='.';
                break;
                }
                i+=slashlen;
            }

        }
        ans[anslen]='\0';
        printf("%s\n",ans);
    }
    del_root(&root);
}

