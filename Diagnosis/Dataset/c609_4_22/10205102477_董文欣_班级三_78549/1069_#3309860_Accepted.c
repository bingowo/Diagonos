#include <stdio.h>
#include <stdlib.h>

int f(int n, int m) {
    if (n < m) return 0;
    if (n == m) return 1;
    else return 2*f(n-1, m) - f(n-1-m, m) + (1 << (n-m-1));
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && n != -1 && m != -1) {
        printf("%d\n", f(n, m));
    }
    return 0;
}
