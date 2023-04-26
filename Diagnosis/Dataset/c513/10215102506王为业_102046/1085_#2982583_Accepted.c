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
char A[MAXLEN];
char B[MAXLEN];

void s_reverse(char A[],int Alen)
{
    unsigned char tem;
    for(int i=0,j=Alen-1;i<j;++i,--j){
        tem=A[i];
        A[i]=A[j];
        A[j]=tem;
    }
}

int highac_comp(char A[],int Alen,char B[],int Blen)
{
    if(Alen==Blen){
        while(Alen--){
            if(A[Alen]!=B[Alen])
                return A[Alen]-B[Alen];
        }
        return 0;
    }else{
        return Alen-Blen;
    }
}

void highac_minus(char A[],int*p_alen,char B[])//calc A-B
{
    //as pre dealt action
    int len=*p_alen;
    int lent=FALSE;
    for(int i=0;i<len;++i){
        A[i]-=B[i];
        if(lent)
            --A[i];

        if(A[i]<0){
            lent=TRUE;
            A[i]+=10;
        }else{
            lent=FALSE;
        }
    }
    len=MAXLEN-1;
    while(A[len]==0)
        --len;

    *p_alen=len+1;
}

void digitalize(char A[],int alen)
{
    while(alen--){
        A[alen]-='0';
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
        digitalize(A,alen);
        digitalize(B,blen);

        int situ=highac_comp(A,alen,B,blen);
        if(situ==0){
            printf("0\n");
        }else if(situ<0){
            //-(B-A)
            //calc B-A and deal with B
            highac_minus(B,&blen,A);
            putchar('-');
            for(int i=blen-1;i>=0;--i){
                printf("%d",B[i]);
            }
            putchar('\n');
        }else{
            //A-B
            highac_minus(A,&alen,B);
            for(int i=alen-1;i>=0;--i){
                printf("%d",A[i]);
            }
            putchar('\n');
        }
        memset(A,0,MAXLEN*sizeof(A[0]));
        memset(B,0,MAXLEN*sizeof(B[0]));
    }
}

