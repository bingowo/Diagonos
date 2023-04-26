#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int T, *N, *I, **M, n, s, m, i, j, k, l, h, out;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        scanf("%d%d", &n, &m);
        s = (n + 1) * n / 2;
        N = (int *)malloc(sizeof(int) * n);
        I = (int *)malloc(sizeof(int) * s);
        M = (int **)malloc(sizeof(int *) * 2);
        M[0] = (int *)malloc(sizeof(int) * m);
        M[1] = (int *)malloc(sizeof(int) * m);
        memset(I, 0, sizeof(int) * 100);
        for (j = 0;j < n;j++){
            scanf("%d", &N[j]);
        }
        for (j = 0;j < m;j++){
            scanf("%d%d", &M[0][j], &M[1][j]);
        }
        l = 0;
        for (j = 0;j < n;j++){
            for (k = 0;k < n - j;k++){
                for (h = j;h < n - k;h++){
                    I[l] += N[h];
                }
            l += 1;
            }
        }
        qsort(I, s, sizeof(int), cmp);
        printf("case #%d:\n", i);
        for (j = 0;j < m;j++){
            out = 0;
            for (k = M[0][j] - 1;k < M[1][j];k++){
                out += I[k];
            }
            printf("%d\n", out);
        }
        free(N);free(M);free(I);
    }
    return 0;
}
