#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    int N,R;
    int r[32];
    int i,j;
    scanf("%d",&t);
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(t--)
    {
        scanf("%d %d",&N,&R);
        if(N<=0)
        {
            N=-N;
            printf("-");
        }
        do{
            i=0;
            r[i]=N%R;
            N=N/R;
            i++;
            j=i;
        }while(N!=0);
        while(j>=0){
            printf("%c",table[r[j]]);
            j--;
        }
    }
    return 0;
}
