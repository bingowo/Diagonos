#include <stdio.h>
#include <stdlib.h>

int num(int n, int p, int m, int t) {
    if (m == 0) {
        if (p == t)
            return 1;
        else
            return 0;
    } else {
        if (p == 1)
            return num(n, 2, m - 1, t);
        else if (p == n)
            return num(n, p - 1, m - 1, t);
        else
            return num(n, p - 1, m - 1, t) + num(n, p + 1, m - 1, t);
    }
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int n, p, m, t;
        scanf("%d%d%d%d", &n, &p, &m, &t);
        printf("%d\n", num(n, p, m, t));
    }
    return 0;
}
