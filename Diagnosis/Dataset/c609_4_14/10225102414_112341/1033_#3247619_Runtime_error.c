#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T, i, j, k, n, m, N[600] = {0}, O[100];
    char I[101], *result, C[6], B[64] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%s", I);
        for (j = 0;j < strlen(I);j++){
            n = I[j];
            k = 0;
            while (n != 0){
                N[(j + 1) * 8 - 1 - k] = n % 2;
                n /= 2;
                k += 1;
            }
        }
        if ((j * 8) % 3 != 0){
            m = (j * 8) / 6 + 1;
        }else{
            m = (j * 8) / 6;
        }
        for (j = 0;j < m;j++){
            for (k = 0;k < 6;k++){
                C[k] = N[j * 6 + k] + '0';
            }
            O[j] = strtol(C, &result, 2);
        }
        printf("case #%d:\n", i);
        for (j = 0;j < m;j++){
            printf("%c", B[O[j]]);
        }
        while (m % 4 != 0){
            printf("=");
            m += 1;
        }
        printf("\n");
    }
    return 0;
}