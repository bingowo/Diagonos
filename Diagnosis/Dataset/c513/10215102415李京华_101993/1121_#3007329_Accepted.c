#include <stdio.h>
#include <string.h>

int abs(int n) {
    return n < 0 ? -n : n;
}

int main() {
    int n;
    scanf("%d", &n);
    int w[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    int f[n+1][sum+1];
    for (int i = 0; i <= n; ++i)
        for(int j = 0; j <= sum; ++j)
            f[i][j] = 0;

    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= sum; ++j) {
            if (f[i-1][j]) {
                f[i][j] = 1;
                f[i][abs(j+w[i-1])] = 1;
                f[i][abs(j-w[i-1])] = 1;
            }
        }

    for (int i = 1; i <= sum; ++i)
        printf("%d", f[n][i]);

    return 0;
}