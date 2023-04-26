//digsy\1087.c

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

char A[110];
int Alen;

int isplus;

void highac_Acarry()
{
    for(int i=0;i<Alen;++i){
        if(A[i]>=10){
            A[i+1]+=A[i]/10;
            A[i]%=10;
        }
    }
    if(A[Alen]!=0)
        ++Alen;
}

int not_goal()
{
    char before=A[0];
    for(int i=1;i<Alen;++i){
        if(A[i]==before)
            return TRUE;
        before=A[i];
    }
    return FALSE;
}

void make_it()
{
        while(not_goal()){
            char before=A[Alen-1];
            for(int i=Alen-2;i>=0;--i){
                if(before==A[i]){
                    ++A[i];
                    highac_Acarry();
                    isplus=TRUE;
                    break;
                }
                before=A[i];
            }
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
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        memset(A,0,Alen*sizeof(A[0]));
        isplus=FALSE;
        scanf("%s",A);
        Alen=strlen(A);
        for(int i=0;i<Alen;++i){
            A[i]-='0';
        }
        for(int i=0,j=Alen-1;i<j;++i,--j){
            char tem=A[i];
            A[i]=A[j];
            A[j]=tem;
        }
        //deal area---------------------------------
        make_it();

        if(!isplus){
            ++A[0];
            highac_Acarry();
            make_it();
        }
        //deal area------------------------
        for(int i=Alen-1;i>=0;--i){
            printf("%d",A[i]);
        }
        putchar('\n');
    }
}

