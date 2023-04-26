#include <stdio.h>
#include <stdlib.h>

int main()
{
   char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int T,N,R,t[10000],i=0;
   int sign=1;
   scanf("%d\n",&T);
   while(scanf("%d %d\n",&N,&R)!=EOF){
    i=0;
    if(N<0){
        sign=-1;
        N=-N;
    }
    do{
        t[i++]=N%R;
        N=N/R;
    }
    while(N!=0);
    if(sign==-1)
        printf("-");
    i--;
    while(i>=0)
        printf("%c",table[t[i--]]);
    printf("\n");
   }
    return 0;
}
