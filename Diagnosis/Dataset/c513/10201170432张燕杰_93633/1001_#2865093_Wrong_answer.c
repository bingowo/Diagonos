#include<stdio.h>

int main()
{
    int T;
    int N;
    int R;
    char array[36] ={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        scanf("%d %d",&N,&R);
        while(N>=R)
        {
            if(N<=R)
            {
                printf("%c",array[N]);
            }
            else
            {
                printf("%c",array[N/R]);
                N = N%R;
            }

        }
        printf("%c\n",array[N]);
    }
    return 0;
}
