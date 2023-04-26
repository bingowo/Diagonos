#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, N, cnt=1;
    char *R;
    int RR=0;
    char *out = {'0'};
    char *x = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        scanf("%d%s", &N, R);

        for(int i=0; (R[i]>='0' && R[i]<='9') || (R[i]>='A' && R[i]<='Z'); i++)
        {
            if(R[i]>='0' && R[i]<='9')
                RR = 10*RR + R[i] - '0';
            if(R[i]>='A' && R[i]<='Z')
                RR = 10*RR + R[i] - 'A';
        }

        if(N == 0)
        {
            printf("0");
        }
        while(N != 0)
        {
            out[cnt] = x[N%RR];
            cnt++;
            N /= RR;
        }
        for(int i=cnt; i>0; --i)
        {
            printf("%c", out[i]);
        }

        printf("\n");

        cnt = 1;
    }

    return 0;
}
