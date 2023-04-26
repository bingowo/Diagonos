//digsy\1085.c

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
#define MAXLEN 510
unsigned char A[MAXLEN];
unsigned char B[MAXLEN];

void s_reverse(unsigned char A[],int Alen)
{
    unsigned char tem;
    for(int i=0,j=Alen-1;i<j;++i,--j){
        tem=A[i];
        A[i]=A[j];
        A[j]=tem;
    }
}


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    while(scanf("%s %s",A,B)!=EOF){
        int alen=strlen(A);
        int blen=strlen(B);
        s_reverse(A,alen);
        s_reverse(B,blen);

    }
}

