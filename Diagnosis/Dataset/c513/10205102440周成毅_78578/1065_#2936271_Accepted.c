#include <stdio.h>

#define MAXN 21

int a[MAXN];
int aa[MAXN];
int f[MAXN];
int fa[MAXN];

int main() {
    f[0] = 0;
    a[0] = 0;
    int a1, n, am, fx;
    scanf("%d %d %d %d\n", &a1, &n, &am, &fx);
    f[1] = a1;
    f[2] = a1;
    fa[0] = 0;
    fa[1] = a1;
    fa[2] = a1;
    a[1] = a1;
    int x;
    a[2] = 1;
    aa[0] = 0;
    aa[1] = a1;
    aa[2] = 0;
    for (int i = 3; i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
        aa[i] = aa[i - 1] + aa[i - 2];
        //printf("%d %d\n", a[i], a[i-1]);
    }
    for (int i = 3; i < n; i++) {
        f[i] = f[i - 1] + a[i - 2];
        fa[i] = fa[i - 1] + aa[i - 2];
        //printf("%d %d\n", f[i], fa[i]);
    }
    x = (am - fa[n - 1]) / (f[n - 1] - fa[n - 1]);
    for (int i = 3; i < n; i++)
        f[i] = (f[i] - fa[i]) * x + fa[i];
    printf("%d\n", f[fx]);
    return 0;
}