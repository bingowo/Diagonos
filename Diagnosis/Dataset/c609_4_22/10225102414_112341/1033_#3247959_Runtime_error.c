#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int T, i, j, k, l, n, m;
    long O[300] = {0};
    char I[101], *result = NULL, o[7], C[16], B[64] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%s", I);
        memset(O, 0, sizeof(O));
        memset(o, '0', sizeof(o));
        memset(C, '0', sizeof(C));
        l = 0;m = 0;
        for (j = 0;j < strlen(I);j++){
            n = I[j];
            for (k = 0;n != 0;n /= 2){
                C[m + 7 - k] = n % 2 + '0';
                k += 1;
            }
            m += 8;
            while (m >= 6){
                for (k = 0;k < 6;k++){
                    o[k] = C[k];
                }
                O[l++] = strtol(o, &result, 2);
                memset(o, '0', sizeof(o));
                memset(C, '0', 6);
                for (k = 6;k < m;k++){
                    C[k - 6] = C[k];
                }
                m -= 6;
                for (k = m;k < 16;k++){
                    C[k] = '0';
                }
            }
        }
        if (m != 0){
            for (k = 0;k < 6;k++){
                o[k] = C[k];
            }
            O[l++] = strtol(o, &result, 2);
            memset(o, '0', sizeof(o));
            memset(C, '0', 6);
        }
        printf("case #%d:\n", i);
        for (j = 0;j < l;j++){
            printf("%c", B[O[j]]);
        }
        while (l % 4 != 0){
            printf("=");
            l += 1;
        }
        printf("\n");
    }
    return 0;
}
