#include <stdio.h>
int main(void)
{
    int T;
    scanf("%d",&T);
    int i, j, fib[121][27], n;
    for(i=0; i<121; i++) for(j=0; j<27; j++) fib[i][j]=0;
    fib[1][0]=1;
    for(i=2; i<121; i++)
        for(j=0; j<26; j++)
        {
            fib[i][j]+=(fib[i-1][j]+fib[i-2][j]);
            fib[i][j+1]=fib[i][j]/10;
            fib[i][j]%=10;
        }
        for(i=0; i<T; i++)
        {
            scanf("%d",&n);
            printf("case #%d:\n",i);
            for(j=26; j+1; j--)
                if(fib[n][j]) break;
            for(;j+1; j--)
                printf("%d",fib[n][j]);
            if(n==0) printf("0");
            printf("\n");
        }
    return 0;
}