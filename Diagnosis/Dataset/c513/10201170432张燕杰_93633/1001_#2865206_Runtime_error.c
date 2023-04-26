#include<stdio.h>

int main()
{
    int T;
    int N;
    int R;
    char array[36] ={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char stack[100]={'0'};
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int n = 0;
        scanf("%d %d",&N,&R);
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

