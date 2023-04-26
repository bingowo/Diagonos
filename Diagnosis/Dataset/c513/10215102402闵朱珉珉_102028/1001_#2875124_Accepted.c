#include <stdio.h>
int main()
{
    int T,N,R,i,m,sign;
    char s[32],table[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf ("%d",&T);
    for (int k=0;k<T;k++)
    {   i=0;
        scanf("%d%d",&N,&R);
        if (N<0) {sign=1;N=-N;}
        else sign=0;
        do {m=N%R;N=N/R;s[i++]=table[m];}
        while (N!=0);
        if (sign) printf("%c",'-');
        while (i>0)
            printf("%c",s[--i]);
        printf("\n");
    }
    return 0;

}

