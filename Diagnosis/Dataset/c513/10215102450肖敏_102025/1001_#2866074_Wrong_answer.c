#include <stdio.h>

int main() {
    int N,R,T,s,k,i = 0,j = 0;
    int a[32];
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d",&T);
    while (i < T)
    {
        s = 0;
        scanf("%d%d",&N,&R);
        i ++;
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
        for(k = j ; k >= 0;k --)
        {
            printf("%d",table[a[k]]);
        }
    }
    return 0;
}
