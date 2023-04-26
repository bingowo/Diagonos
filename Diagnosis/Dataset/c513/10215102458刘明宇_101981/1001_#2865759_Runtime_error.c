#include <stdio.h>
#include <stdlib.h>
//ju bu zidongbianliang buhui bianwei 0 quanjubianliang chushizhi wei 0
int main()
{
    int m,t,r;
    scanf("%d", &t);
    int num = 0;
    char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (num < t)
    {
        scanf("%d %d", &m,&r);
        int y = 1;
        if (m < 0) { m = -m; y = -1;}
        int L[32];
        int i = 0;
        do { L[i++] = table[m % r]; m = m / r;} while(m);
        
        if (y = -1){printf('-');}
        for(;i>=0; i--) {printf("%c", L[i]);}
        num++;

    }
    return 0;
}
