//digsys\1014.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
/*
character: the information of the question is not full.
we have to cover some pos
In fact,we have to find our own ways
*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
unsigned char thr_bepoint[100];
unsigned char thr_afpoint[100];
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
   int A,B;
   scanf("%d %d",&A,&B);
   int inte=A/B;
   int floa=A%B;
   int len_af=0;
   int len_be=0;
   while(inte!=0){
    thr_bepoint[len_be++]=inte%3;
    inte/=3;
   }
   int tem=1;
   while(tem<B){
    thr_afpoint[len_af++]=floa%3;
    floa/=3;
    tem*=3;
   }
   //end of inputing


   for(int i=0;i<len_af-1;++i){
    ++thr_afpoint[i];
    thr_afpoint[i+1]+=thr_afpoint[i]/3;
    thr_afpoint[i]%=3;
   }
   ++thr_afpoint[len_af-1];
   if(thr_afpoint[len_af-1]>=3){
    thr_bepoint[0]+=thr_afpoint[len_af-1]/3;//then +1
    if(len_be==0)len_be=1;
    thr_afpoint[len_af-1]%=3;
    }
   for(int i=0;i<len_be-1;++i){
    ++thr_bepoint[i];
    thr_bepoint[i+1]+=thr_bepoint[i]/3;
    thr_bepoint[i]%=3;
   }
if(len_be!=0){
   ++thr_bepoint[len_be-1];
   if(thr_bepoint[len_be-1]>=3){
    thr_bepoint[len_be]=thr_bepoint[len_be-1]/3+1;//+1 is a key
    thr_bepoint[len_be-1]%=3;//len_be-2
    ++len_be;
   }
}
    //end of calcultion
    int endaf=0;
    while(endaf<len_af&&thr_afpoint[endaf]==1)++endaf;

    while(len_be>0&&thr_bepoint[len_be-1]==1)--len_be;
if(len_be!=0){
   for(int i=len_be-1;i>=0;--i){
    switch(thr_bepoint[i]){
    case 0:
        putchar('2');
        break;
    case 1:
        putchar('0');
        break;
    case 2:
        putchar('1');
        break;
    }
   }

}else{
    putchar('0');
}
if(endaf!=len_af){

    putchar('.');
   for(int i=len_af-1;i>=endaf;--i){
    switch(thr_afpoint[i]){
    case 0:
        putchar('2');
        break;
    case 1:
        putchar('0');
        break;
    case 2:
        putchar('1');
        break;
    }
   }

}

}
