#include <stdio.h>

int main() {
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a[32];
        int i=0;
        int N,R;
        scanf("%d%d",&N,&R);
        int sign;
        sign=N>0?1:-1;
        N=N*sign;
        if(N==0)
            printf("0\n");
        do {
            a[i++]=N%R;
            N=N/R;
        }while(N>0);
        if(sign==-1)
            printf("-");
        while(i>0)
        {
            printf("%c",table[a[--i]]);
        }
        printf("\n");
    }
    return 0;
}
