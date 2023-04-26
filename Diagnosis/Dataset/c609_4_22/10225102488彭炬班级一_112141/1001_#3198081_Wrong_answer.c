#include <stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int T,N,R;
    scanf("%d",&T);
    int i=1;
    while(i<=T)
    {
        scanf("%d %d",&N,&R);
        char s[100];
        int j=0;
        while(N!=0)
        {
            s[j]=table[N%R];
            N/=R;
            j++;
        }
        while(j>=0)
            printf("%c",s[--j]);
            printf("\n");
        i++;
    }
    return 0;
}
