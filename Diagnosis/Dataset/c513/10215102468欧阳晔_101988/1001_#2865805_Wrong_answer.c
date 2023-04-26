#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,i,j,a[33],m=0;
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ-";

    scanf("%d",&i);
    for(int k=0;k<i;k++)
    {
        scanf("%d%d",&N,&R);
        int m =1;
        if(N<0) m=-1,N=-N;
        int j=0;
        do
        {
           a[j++]=N%R;
           N=N/R;
        }
        while(N);
        if(m) printf("-");
        for(j--;j>=0;j=j-1)
            printf("%c",table[a[j]]);
         printf("\n");
    }
    return 0;
}
