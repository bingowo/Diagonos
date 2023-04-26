#include <stdio.h>
#include <stdlib.h>



int main()
{
    int T; scanf("%d",&T);
    const char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<T;i++)
     {
        int N,R;scanf("%d%d",&N,&R);
        int sign=1;
        if(N<0) sign=-1,N=-N;
        char a[33];
        int k=0;
        do{
            a[k++]=table[N%R];
            N = N / R;
        } while (N);
        if(sign<0) printf("-");
        for(k=k-1;k>=0;k--) printf("%c",*(a+k));
        printf("\n");
    }
    return 0;
}


