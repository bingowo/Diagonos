#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, j, k, N[30], c;
    long long a, b, n = 0, m, judge;
    memset(N, 0, 30 * sizeof(int));
    scanf("%lld%lld", &a, &b);
    m = a % b;
    judge = m;
    while (a / b != 0){
        n += 1;
        a -= b;
    }
    for (i = 1;n != 0;i++){
        N[i] = n % 3;
        n /= 3;
    }
    for (j = 1;j < i / 2 + 1;j++){
        c = N[j];
        N[j] = N[i - j];
        N[i - j] = c;
    }
    N[i++] = -1;
    while (m != 0){
        m *= 3;
        for (k = 0;m >= b;k += 1){
            m -= b;
        }
        N[i++] = k;
    }
    for (j = i - 1;j >= 0;j--){
        if (N[j] == -1){
            continue;
        }
        N[j] += 1;
        if (N[j] >= 3){
            N[j] -= 3;
            if (N[j - 1] != -1){
                N[j - 1] += 1;
            }else{
                N[j - 2] += 1;
            }
        }
        N[j] -= 1;
        if (N[j] == -1){
            N[j] = 2;
        }
    }
    if (N[0] != 0 || N[1] == -1){
        printf("%d", N[0]);
    }
    if (judge == 0){
        i -= 1;
    }
    for (j = 1;j < i;j++){
        if (N[j] == -1){
            printf(".");
        }else {
            printf("%d", N[j]);
        }
    }
    return 0;
}

