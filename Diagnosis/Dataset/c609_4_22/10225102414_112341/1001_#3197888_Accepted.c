#include <stdio.h>

int main()
{
    char W[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", re[100];
    int i = 0, j,  N, R, num;
    scanf("%d", &N);
    while (i < N){
        j = 0;
        scanf("%d%d", &num, &R);
        if (num < 0){
            printf("-");
            num *= (-1);
        }else if(num == 0){
            printf("0\n");
            continue;
        }
        while (num != 0){
            re[j] = W[num % R];
            num /= R;
            j += 1;
        }
        for(j -= 1;j >= 0;j--){
            printf("%c", re[j]);
            if(j == 0){
                printf("\n");
            }
        }
        i += 1;
    }
    return 0;
}