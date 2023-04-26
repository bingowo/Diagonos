#include <stdio.h>

int main()
{
    char W[] = {0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ}, re[100];
    int i = 0, j, m, N, R, num;
    scanf("%d\n", &N);
    while (i < N){
        re[100] = {0};
        j = 0;
        k = 0;
        m = 0;
        scanf("%d %d\n", &num, &R);
        if (num < 0){
            printf("-");
        }else if(num == 0){
            printf("0\n");
            continue;
        }
        while (N != 0){
            re[j] = W[N % R];
            N /= R;
            j += 1;
        }
        for(j -= 1;j >= 0;j--){
            printf("%c", re[j]);
            if(j == 0){
                printf("\n");
            }
        }
    }
    return 0;
}