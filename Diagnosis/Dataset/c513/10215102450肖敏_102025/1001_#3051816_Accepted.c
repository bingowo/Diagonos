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
            a[i]=N%R;
            i++;
            N=N/R;
        }while(N>0);
        if(sign==-1)
            printf("-");
        for(int j=i-1;j>=0;j--)
        {
            printf("%c",table[a[j]]);
        }
        printf("\n");
    }
    return 0;
}
