#include <stdio.h>
int main()
{
    int T,N,R,i,m;
    char s[32],table[36]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf ("%d",&T);
    for (int k=0;k<T;k++)
    {   i=0;
        scanf("%d%d",&N,&R);
        do {m=N-N/R*R;N=N%R;s[i++]=table[m];}
        while (N==0);
        while (i>=0)
            printf("%c",s[i--]);
    }
    return 0;

}
