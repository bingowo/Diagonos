#include <stdio.h>

long long walk(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    else if (n == 4)
        return 8;
    else
        return walk(n - 1) + walk(n - 2) + walk(n - 3) + walk(n - 4);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        printf("case #%d:\n",i);
        printf("%lld\n", walk(n));
    }
    return 0;
}
