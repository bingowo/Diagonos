#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,T,a[33];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    scanf("%d",&T);
    for(int k=0;k<i;k++)
    {
        scanf("%d%d",&N,&R);
        int flag = 0;
        if(N<0) flag=-1,N=-N;
        int i = 0;
        do
        {
           a[i++]=N%R;
           N=N/R;
        }
        while(N);
        if(flag) printf("-");
        for(i--;i>=0;i=i-1)
            printf("%c",table[a[i]]);
         printf("\n");
    }
    return 0;
}
