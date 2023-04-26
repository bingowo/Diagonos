#include <stdio.h>

long long int Fei(int n) {
    int i;
    long long a[n];
    if(n ==0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    else {
        a[0] =0;
        a[1] = 1;
        a[2] = 1;
        for (i = 3; i <= n; i++)
            a[i] = a[i - 1] + a[i - 2] + a[i - 3];
        return a[n];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int n;
        long long m;
        scanf("%d", &n);
        m =Fei(n);
        printf("case #%d:\n%lld\n", i, m);
    }
    return 0;
}
