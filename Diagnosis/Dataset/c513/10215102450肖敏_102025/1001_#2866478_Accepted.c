#include <stdio.h>

int main() {
    int N,R,T,s,i,j;
    int a[32];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&T);
    for(i = 0;i < T;i ++)
    {
        j = 0;
        s = 0;
        scanf("%d%d",&N,&R);
        if(N < 0)
        {
            s = 1;
            N = -N;
        }
        do {
            a[j++] = N % R;
            N /= R;
        }
        while(N);
        if(s)
        {
            printf("-");
        }
        while(j > 0)
        {
            printf("%c",table[a[--j]]);
        }
        printf("\n");
    }
    return 0;
}
