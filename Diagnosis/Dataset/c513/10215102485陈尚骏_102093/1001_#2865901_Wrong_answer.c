#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T,N,R;
    int x;
    int ch[32];
    scanf("%d",&T);
    for(int i=0;i<=T;i++)
    {
        scanf("%d %d",&N,&R);
        do{
        int j=0;
        if(N<0) N=-N;
        ch[j]=N%R;
        N=N/R;
        j++;
        x=j;
        }while(N>0);
        char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=x;i>=0;i--)
        {
            printf("%c",table[ch[x]]);
        }
    }
    return 0;
}
