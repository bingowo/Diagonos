//string\1056.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/

#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

char words[4001][16];
char str[5010];

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    getchar();
    int maxlen=0,temlen;
    for(int in=0;in<n;++in){
        scanf("%s",words[in]);
        temlen=strlen(words[in]);
        if(temlen>maxlen)
            maxlen=temlen;
    }
    scanf("%s",str);
    char* beg=str;
    char temword[18];

    int firstappear=TRUE;

    while(*beg){
        int L=maxlen;
        int found=FALSE;
        while(L!=1){
            for(int i=0;beg[i]&&i<L;++i){
                temword[i]=beg[i];
            }
            temword[L]='\0';
            for(int in=0;in<n;++in){
                if(strcmp(temword,words[in])==0){
                    found=TRUE;//we found it
                    break;
                }
            }
            if(found){
                break;//after found,temword contains all
            }
            --L;
        }
        if(firstappear){
            firstappear=FALSE;
        }else{
            putchar(' ');
        }
        if(L==1){
            putchar(*beg);
            ++beg;
        }else{
            printf("%s",temword);
            beg+=L;
        }
        
    }
}