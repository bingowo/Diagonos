#include <stdio.h>
#include <stdlib.h>
int Judge(int a, int *w, int n)
{
    if (!a) return 1;
    if (!n) return 0;
    return Judge(a, w + 1, n - 1) || Judge(a + *w, w + 1, n - 1) || Judge(a - *w, w + 1, n - 1);
}
int main()
{
    int i, n, *w, max = 0;
    for (w = malloc(scanf("%d", &n) * sizeof(int));i < n;i++) scanf("%d", &w[i]), max += w[i];
    for (i = 1;i <= max;i++) printf("%d", Judge(i, w, n));
    return 0;
}
