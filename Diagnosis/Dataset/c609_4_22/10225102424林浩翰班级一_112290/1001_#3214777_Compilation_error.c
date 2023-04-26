#include<stdio.h>

char table[]="0123456789ABCDEFGHIJKLMNOPORSTUVWXYZ";
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
    int T;scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        int N,R;
        scanf("%d%d",&N,&R)
        if(N<B)[ printf("_"); N=-N;}
        if(N==a){putchar(table[e]);}
        else{trans(N,R);printf(" n");}
    }
    return 0;
}