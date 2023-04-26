#include <stdio.h>
#include <stdlib.h>

int cmp(const void *_a, const void *_b) {
    if (*(long long*)_a > *(long long*)_b)
        return 1;
    return -1;
}

void Solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &arr[i]);

    int size = n*(n+1)/2;
     long long newArray[size];
    int cnt = 0;
    for (int step = 1; step <= n; ++step) {
        for (int i = 0; i < n - step + 1; ++i) {
            long long sum = 0;
            for (int j = 0; j < step; ++j)
                sum += arr[i+j];
            newArray[cnt++] = sum;
        }
    }

    qsort(newArray, size, sizeof(newArray[0]), cmp);

    // printf("Debug:\n");
    // for (int i = 0; i < cnt; ++i)
    //     printf("%d\n",newArray[i]);
    // printf("End\n");
    
    while (m--) {
        int l, u;
        scanf("%d%d", &l, &u);
        long long sum = 0;
        for (int i = l-1; i < u; ++i)
            sum += newArray[i];
        printf("%lld\n", sum);
    }
}

int main() {
    int n, k = 0;
    scanf("%d", &n);
    while (n--) {
        printf("case #%d:\n", k++);
        Solve();
    }
    return 0;
}