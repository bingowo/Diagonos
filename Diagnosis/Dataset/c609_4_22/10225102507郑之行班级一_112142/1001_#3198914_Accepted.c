#include <stdio.h>
#include <stdlib.h>

int main()
{
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N,R,oi=0,remain;
        scanf("%d %d",&N,&R);
        char outp[33];

        if (N<0){printf("-");N*=-1;}

        do{
            remain=N%R;
            outp[oi++]=table[remain];
            N/=R;
        }while(N);
        for(oi--;oi>=0;oi--)printf("%c",outp[oi]);
        printf("\n");
    }
    return 0;
}
