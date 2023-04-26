#include <stdio.h>
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int N,R;
    scanf("%d %d",&N,&R);
    char s[100];
    int i = 0;
    while(N != 0)
    {
        int n = N % R;
        N /= R;
        if(n < 0)
        {
            n -= R;
            N++;
        }
        s[i++] = table[n];
    }
    while(i >= 0)
            printf("%c",s[--i]);
    return 0;
}
