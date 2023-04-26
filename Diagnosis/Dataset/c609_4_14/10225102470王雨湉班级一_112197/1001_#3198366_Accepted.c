#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void Change(int N,int R)
{
        int sign=(N>=0)?1:-1;
        int n = 0;
        if(sign<0)
                N=-N;
        char s[100];
        do
        {
                int r = N % R;
                s[n++] = table[r];
                N/=R;
        }
        while(N);
        if(sign<0)
                s[n++]='-';
        for(n=n-1;n>=0;n--)
                printf("%c",s[n]);
        printf("\n");
}

int main()
{
    int T,R;
    int N;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
            scanf("%d%d",&N,&R);
            Change(N,R);
    }
    return 0;
}
