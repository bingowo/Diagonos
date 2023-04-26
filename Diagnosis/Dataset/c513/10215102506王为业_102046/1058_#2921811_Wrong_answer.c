//string\1058.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/
#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    char c;
    int bef_slash=FALSE;
    int bef_back=FALSE;
    int strarea=FALSE;
    while((c=getchar())!=EOF){
    if(strarea){
        if(c=='"'){
            if(bef_back){
                putchar('\\');
                bef_slash=FALSE;
            }else{
                strarea=FALSE;
            }
        }
        if(c=='\\')
            bef_back=TRUE;
        else
            bef_slash=FALSE;
        putchar(c);
    }else{
        if(c=='"'&&bef_back==FALSE){
            strarea=TRUE;
            putchar(c);
        }
        else if(c=='/'){
            if(bef_slash){
                while((c=getchar())!=EOF&&c!='\n');
                if(c=='\n')putchar('\n');
                else if(c==EOF)break;
                bef_slash=FALSE;
            }else{
                bef_slash=TRUE;
            }
        }else if(c=='*'&&bef_slash){
            int bef_star=FALSE;
            while((c=getchar())!=EOF){
                if(c=='*')
                    bef_star=TRUE;
                else if(c=='/'&&bef_star)
                    break;
                else
                    bef_star=FALSE;
            }
            bef_slash=FALSE;
        }else{
            if(bef_slash){
                putchar('/');
                bef_slash=FALSE;
            }
            if(c=='\\')
                bef_back=TRUE;
            putchar(c);
        }
    }
    }
}
