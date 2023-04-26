#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(int p, int n, int O[][1000], int m)
{
    int i, j, a;
    for (j = 0;j < p;j++){
        for (i = 999;i >= 3;i--){
            a = O[0][i] * 125;
            O[0][i] = a % 10;a /= 10;
            O[1][i - 1] += a % 10;a /= 10;
            O[1][i - 2] += a % 10;a /= 10;
            O[1][i - 3] += a % 10;a /= 10;
        }
        for (i = 999;i >= 1;i--){
            a = O[0][i] + O[1][i];
            O[0][i] = a % 10;a /= 10;
            O[1][i - 1] += a;
        }
        for (i = 0;i < 1000;i++){
            O[1][i] = 0;
        }
    }
    for (i = 999;i >= 1;i--){
        a = O[0][i] * n;
        O[0][i] = a % 10;a /= 10;
        O[1][i - 1] += a;
    }
    for (i = 999;i >= 1;i--){
        a = O[0][i] + O[1][i];
        O[0][i] = a % 10;a /= 10;
        O[1][i - 1] += a;
    }
    for (i = 0;i < 1000;i++){
        O[1][i] = 0;
    }
    O[0][999 - m] = -1;
}

int main()
{
    int T, i, j, k, n, x, y, a, bre = 0;
    char I[53];
    int O[2][1000], A[1000] = {0};
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        n = 0;
        memset(A, 0, sizeof(A));
        scanf("%s", I);
        for (j = 2;j < strlen(I);j++){
            memset(O, 0, sizeof(O));
            O[0][999] = 1;
            n = (j - 1) * 3;
            bre = 1;
            cal(j - 1, I[j] - '0', O, n);
            for (x = 999;x >= 1 && O[0][x] != -1;x--);
            for (y = 999;y >= 1 && A[y] != -1;y--);
            if (y == 0){
                for (k = x;k < 1000;k++){
                    A[k] = O[0][k];
                }
            }else{
                for (k = x;k < 1000;k++){
                    A[k] = (y < 1000) ? A[y] : 0;
                    y += 1;
                }
                for (k = 999;k > x;k--){
                    a = A[k] + O[0][k];
                    A[k] = a % 10;a /= 10;
                    A[k - 1] += a;
                }
            }
            for (k = strlen(I) - 1;k > j;k--){
                if (I[k] != '0'){
                    bre = 0;
                }
            }
            if (bre == 1){
                break;
            }
        }
        printf("case #%d:\n", i);
        for (k = x;k < 1000;k++){
            if (A[k] == -1){
                printf("0.");
            }else{
                printf("%d", A[k]);
            }
        }
        printf("\n");
    }
    return 0;
}
