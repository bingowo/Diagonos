#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2) {
    return *(int*)p2 - *(int*)p1;
}

int main() {
    int arr_int[100000];
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        scanf("%d", &arr_int[i]);
    qsort(arr_int, n, sizeof(int), cmp);
    long long res = 0;
    for (int i = 0; i != n; i += 2)
        res += arr_int[i] - arr_int[i + 1];
    printf("%lld\n", res);
    return 0;
}