#include <stdio.h>

int main()
{
    int T, i;
    long long n, r;
    scanf("%d", &T);
    for (int t = 0; t < T;t ++){
        scanf("%d", &n);
        long long ans[1000];
        i = 0;
        while (n > 0){
            ans[i] = n % 2333;
            i ++;
            n /= 2333;
        }
        for (int j = i - 1; j >= 0; j --){
            printf("%d ", ans[j]);
        }
        printf("\n");
    }
    return 0;
}
