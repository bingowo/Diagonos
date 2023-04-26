//digsys\1014.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

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
   for(int i=0;i<len_af-1;++i){
    ++thr_afpoint[i];
    thr_afpoint[i+1]+=thr_afpoint[i]/3;
    thr_afpoint[i]%=3;
   }
   ++thr_afpoint[len_af-1];
   thr_bepoint[0]+=thr_afpoint[len_af-1]/3;
   thr_afpoint[len_af-1]%=3;

   for(int i=0;i<len_be-1;++i){
    ++thr_bepoint[i];
    thr_bepoint[i+1]+=thr_bepoint[i]/3;
    thr_bepoint[i]%=3;
   }
   ++thr_bepoint[len_be-1];
   if(thr_bepoint[len_be-1]>=3){
    thr_bepoint[len_be++]=thr_bepoint[len_be-1]/3;
    thr_bepoint[len_be-2]%=3;//len_be-2
   }

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
    putchar('.');
   for(int i=0;i<len_af;++i){
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
