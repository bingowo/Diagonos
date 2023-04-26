#include <stdio.h>

int main()
{
    int T, i;
    long long n;
    scanf("%d", &T);
    for (int t = 0; t < T;t ++){
        scanf("%lld", &n);
        if (n == 0){
            printf("0\n");
            continue;
        }
        long long ans[10];
        i = 0;
        while (n > 0){
            ans[i] = n % 2333;
            i ++;
            n /= 2333;
        }
        for (int j = i - 1; j >= 0; j --){
            printf("%lld ", ans[j]);
        }
        printf("\n");
    }
    return 0;
}
