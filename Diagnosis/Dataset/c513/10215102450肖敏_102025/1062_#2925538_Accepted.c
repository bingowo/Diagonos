#include <stdio.h>

long long int Step(int n) {
    int i;
    long long a[n + 1];
    if (n == 1 || n == 2)
        return n;
    else if (n == 3)
        return 4;
    else {
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        a[4] = 8;
        for (i = 5; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4];
        return a[n];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        long long m;
        scanf("%d", &n);
        m = Step(n);
        printf("case #%d:\n%lld\n", i, m);
    }
    return 0;
}
