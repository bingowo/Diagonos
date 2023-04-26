#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char table[]="0123456789ABCDEFGHIJ";

void Change(int N,int R)
{
        int n = 0;
        char s[100];
        do
        {
                int r = N % R;
                if(r<0)
                {
                        r=N%R-R;
                        N=N/R+1;
                }
                else
                        N/=R;
                s[n++] = table[r];
        }
        while(N);
        for(n=n-1;n>=0;n--)
                printf("%c",s[n]);
        printf("\n");
}

int main()
{
    int N,R;
    scanf("%d%d",&N,&R);
    Change(N,R);
    return 0;
}
