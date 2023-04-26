#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long

ll f[55];
ll dfs(int x) {

 if (f[x] != -1) return f[x];
    if (x == 1) return f[x] = 1;
    else if (x == 2) return f[x] = 2;
    else if (x == 3) return f[x] = 4;
    else if (x == 4) return f[x] = 8;
    else return f[x] = dfs(x - 1) + dfs(x - 2) + dfs(x - 3) + dfs(x - 4);
}
int main () {
    int cas,i;
    ll n;
    scanf ("%d", &cas);
    memset(f, -1, sizeof(f));
    for (i=0;i<cas;i++) {
        printf ("case #%d:\n", i);
        scanf ("%lld", &n);
        printf ("%lld\n", dfs(n));

    }
    return 0;
}
