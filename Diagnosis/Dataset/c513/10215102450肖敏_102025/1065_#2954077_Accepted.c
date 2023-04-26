#include <stdio.h>

int SUB(int n) {
    int i;
    int a[n], b[n];
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    b[0] = 0;
    b[1] = 0;
    b[2] = 1;
    for (i = 3; i <= n; i++) {
        b[i] = b[i - 1] + b[i - 2];
        a[i] = a[i - 1] + b[i - 1] - b[i - 2];
    }
    return a[n];
}
int SUB1(int n)
{
    int i;
    int b[n], c[n];
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 1;
    for (i = 3; i <= n; i++) {
        b[i] = b[i - 1] + b[i - 2];
        c[i] = c[i - 1] + b[i] - b[i - 1];
    }
    return c[n];
}

int main() {
    int a, n, m, x;
    scanf("%d%d%d%d", &a, &n, &m, &x);
    int t,su,sv,sx1,sx2,num;
    su = SUB(n-1);
    sv= SUB1(n-1);
    sx1= SUB(x);
    sx2= SUB1(x);
    t = (m - su*a)/sv;
    num = sx1*a + sx2*t;
    printf("%d\n",num);
    return 0;
}
