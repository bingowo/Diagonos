#include <stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
void trans(int N,int R)
{
    if(N>0)
    {
        trans(N/R,R);
        putchar(table[N%R]);
    }
}
int main()
{
    int T,N,R,i;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        if(N<0)
        {
            printf("-");
            N=-N;
        }
        else if(N==0)
            printf("0");
        else
            trans(N,R);
        printf("\n");
    }
    return 0;
}