//string\1041.c
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
unsigned char temnum[200];
unsigned hextodec(int temlen)
{
    unsigned ans=0;
    unsigned t=1;
    for(int i=temlen-1;i>=0;--i){
        ans+=t*temnum[i];
        t*=16;
    }
    return ans;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int ispast_zero=FALSE;
    int nothing=TRUE;
    int temlen=0;
    char c;
    while((c=getchar())!=EOF){
        if(c=='0'){
            ispast_zero=TRUE;
        }else if(c=='x'){
            if(ispast_zero){

    temlen=0;
    while((c=getchar())!=EOF){
        if('0'<=c&&c<='9')
            temnum[temlen++]=c-'0';
        else if('a'<=c&&c<='f')
            temnum[temlen++]=c-'a'+10;
        else
            break;
    }
    if(temlen!=0){
        nothing=FALSE;
        printf("%u ",hextodec(temlen));
    }
    if(c==EOF)
        break;
            }
        }
    }
    if(nothing)
        printf("-1");
}
