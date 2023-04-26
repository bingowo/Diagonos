#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void trans(int N,int R)
{
    if (N>0)
    {
        trans(N/R,R);
        putchar(table[N%R]);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N,R;
        scanf("%d %d",&N,&R);
        if(N<0){printf("-");N=-N;}
        if(N==0)printf("0");
        else trans(N,R);
        printf("\n");
    }
    return 0;
}


/*
int main()
{
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
*/
