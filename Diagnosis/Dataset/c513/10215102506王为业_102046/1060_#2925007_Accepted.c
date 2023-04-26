//string\1060.c
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

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int digmode=FALSE;
    char c;
    int maxlen=0;
    int temlen=0;
    while((c=getchar())!=EOF){
        if(digmode){
            if(isdigit(c)){
                ++temlen;
            }else{
                digmode=FALSE;
                if(temlen>maxlen)
                    maxlen=temlen;
                temlen=0;
            }
        }else{
            if('1'<=c&&c<='9'){
                ++temlen;
                digmode=TRUE;
            }
        }
    }
    printf("%d",maxlen);
}
