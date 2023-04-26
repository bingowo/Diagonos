#include <stdio.h>

int n, t;
long long f(int cur, int rem) {
    if (rem == 0 && cur == t) return 1;
    if (rem == 0 && cur != t) return 0;
    if (rem > 0 && cur == 1) return f(cur + 1, rem - 1);
    if (rem > 0 && cur == n) return f(cur - 1, rem - 1);
    else return f(cur + 1, rem - 1) + f(cur - 1, rem - 1);
}

int main () {
    int cas, i;
    scanf ("%d", &cas);
    for (i = 0; i < cas; i++) {
        int s, rem;
        scanf ("%d%d%d%d", &n, &s, &rem, &t);
        if (t > n) printf("%d\n", 0);
        else printf("%lld\n", f(s, rem));
    }
    return 0;
}