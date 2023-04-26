#include <stdio.h>

int main()
{
    int T, i = 0, j;
    unsigned long long n;
    scanf("%d", &T);
    for( ;i < T;i++){
        j = 0;
        scanf("%llu", &n);
        if (n == 0){
            printf("0\n");
        }
        for ( ;n != 0;j += 1){
            a[j] = n % 2333;
            n /= 2333;
        }
        for (j -= 1;j >= 0;j--){
            printf("%d ", a[j]);
            if (j == 0){
                printf("\n");
            }
        }
    }
    return 0;
}