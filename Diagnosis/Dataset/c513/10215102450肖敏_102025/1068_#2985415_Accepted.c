#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

long long int IT(int n, int m) {
    long long *p = malloc(sizeof(long long int) * (n + 1));
    memset(p, 0, 8 * (n + 1));
    for (int i = 0; i < n + 1; i++) {
        if (i < m) {
            p[i] = 0;
        } else if (i == m) {
            p[i] = 1;
        } else {
            p[i] = p[i - 1] * 2 + pow(2, i - m - 1) - p[i - m - 1];
        }
    }
    long long temp = p[n];
    free(p);
    return temp;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while (n != -1 && m != -1) {
        printf("%lld\n", IT(n, m));
        scanf("%d%d", &n, &m);
    }
    return 0;
}
