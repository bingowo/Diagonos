#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
int main() {
    int T;
    scanf("%d",&T);
    int *v = malloc(1000000 * sizeof(int));
    int *p = v;
    for(int i = 0; i < T; i++) {
        scanf("%d",p++);
    }
    qsort(v, T, sizeof(int), cmp);
    int r = 0;
    for(int i = 0; i < T; i += 2) {
        r += abs(v[i + 1] - v[i]);
    }
    printf("%d\n", r);
    free(v);
    return 0;
}
