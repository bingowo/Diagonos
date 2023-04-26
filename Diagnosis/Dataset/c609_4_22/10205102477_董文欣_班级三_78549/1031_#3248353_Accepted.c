#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int a[1001] = {0};
int b[500501] = {0};
int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        //输入
        int n,m; //n为原数组的元素个数,m为L和U
        scanf("%d %d", &n, &m);

        for (int j = 1; j <= n; j++) {scanf("%d", &a[j]); a[j] += a[j-1];} //printf("---%d ", a[j]);}
        //printf("\n");


        int cnt = 1;
        for (int j = 1; j <= n; j++) { //外层为1,2...n,子数组
            for (int k = 1; k <= n - j + 1; k++) {
                b[cnt++] = a[k + j - 1] - a[k - 1];
            }
        }
        qsort(b, cnt - 1, sizeof(b[1]), cmp);
//        printf("---%d\n",cnt);
//        for (int j = 1; j < cnt; j++) {
//            printf("---%d ", b[j]);
//        }
//        printf("\n");
        printf("case #%d:\n", i);
        for (int j = 0; j < m; j++) {
            int L, U;
            scanf("%d %d",&L, &U);
            long long ans = 0;
            for (int j = L; j <= U; j++) {
                ans += b[j];
//                printf("---%d ",b[j]);
            }
            printf("%lld\n", ans);
        }

    }
    return 0;
}
