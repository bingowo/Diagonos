#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, N, R, cnt=1;
    char *out = {'0'};
    char *x = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        scanf("%d%d", &N, &R);

        if(N == 0)
        {
            printf("0");
        }
        while(N != 0)
        {
            out[cnt] = x[N%R];
            cnt++;
            N /= R;
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
