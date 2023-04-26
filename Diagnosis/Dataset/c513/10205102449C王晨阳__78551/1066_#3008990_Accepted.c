#include <stdio.h>
#include <stdlib.h>

int count, t/*final_floor*/, n/*total_floors*/;

void level(int p/*floor*/, int m/*minutes*/) {
    if (m <= 0) {
        if (p == t) count++;
        return;
    }
    if (p == 1) level(2, m - 1);
    else if (p == n) level(n - 1, m - 1);
    else {
        level(p + 1, m - 1);
        level(p - 1, m - 1);
    }
}

int main() {
    int T, p, m;
    scanf("%d", &T);
    while (T--) {
        count = 0;
        scanf("%d%d%d%d", &n, &p, &m, &t);
        level(p, m);
        printf("%d\n", count);
    }
    return 0;
}
