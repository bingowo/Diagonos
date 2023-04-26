#include<stdio.h>

int main()
{
    long long int T;
    long long int N;
    long long int R;
    char array[36] ={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char stack[10000]={'0'};
    scanf("%lld",&T);
    for(int i = 0;i<T;i++)
    {
        int n = 0;
        scanf("%lld %lld",&N,&R);
        if(N<0)
        {
            printf("-");
            N = -N;
        }
        while(N>=R)
        {
            if(N<=R)
            {
                stack[n]=array[N];
                n++;
            }
            else
            {
                stack[n]=array[N%R];
                N = N/R;
                n++;
            }

        }
        stack[n]=array[N];
        for(;n>=0;n--)
        {
            printf("%c",stack[n]);
        }
        printf("\n");
    }
    return 0;
}
