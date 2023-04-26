#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n=1,T,N,R,t[10000],i=0;
   scanf("%d\n",&T);
   while(n<T){
    scanf("%d %d\n",&N,&R);
    do{
        t[i++]=N%R;
        N=N/R;
    }
    while(N!=0);
    i--;
    while(i>=0){
        if(t[i]>9)
            printf("%c",t[i--]-10+'A');
        else
            printf("%c",t[i--]-'0');
    }
    printf("\n");
    n++;
   }
    return 0;
}
