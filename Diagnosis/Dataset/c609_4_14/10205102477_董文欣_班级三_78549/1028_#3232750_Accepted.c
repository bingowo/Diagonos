#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *aa = (int *)a;
    int *bb = (int *)b;

    while (*aa != -1 && *bb != -1 && *aa==*bb) {aa++;bb++;}
    return *bb - *aa;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int data[1001][51];
        for (int i = 0; i < N; i++) {
            int j = 0;
            while (scanf("%d",&data[i][j]) && data[i][j] != -1) j++;
         }

        qsort(data, N, sizeof(data[0]), cmp);

        for (int i = 0; i < N; i++) {
            int j = 0;
            while (data[i][j] != -1) {printf("%d ",data[i][j]); j++;}
            printf("\n");
        }
    }
    return 0;
}
