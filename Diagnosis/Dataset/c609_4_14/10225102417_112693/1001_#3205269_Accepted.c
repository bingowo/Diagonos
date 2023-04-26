#include <stdio.h>
#include <stdlib.h>

char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void trans(int N,int R)
{
    if(N>0)
    {   trans(N/R,R);
        putchar(table[N%R]);
    }
}
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++)
    {   int N,R;
        scanf("%d%d",&N,&R);
        if(N<0)
        {printf("-");N=-N;}
        if(N==0)putchar(table[0]);
        else trans(N,R);
        printf("\n");
    }
    return 0;
}

