#include <stdio.h>
#include <stdlib.h>

int f(int n, int p, int m, int t) {
    if (m == 0 && p != t) return 0;
    else if (m == 0 && p == t) return 1;
    else if (m > 0 && t == 1) return f(n, p, m - 1, t + 1);
    else if (m > 0 && t == n) return f(n, p, m - 1, t - 1);
    else return f(n, p, m - 1, t + 1) +  f(n, p, m - 1, t - 1);
}

int main()
{
    int cas;
    scanf("%d", &cas);

    for (int i = 0; i < cas; i++) {
        int n,p,m,t;
        scanf("%d %d %d %d", &n, &p, &m, &t);
        printf("%d\n", f(n,p,m,t));
    }
    return 0;
}
