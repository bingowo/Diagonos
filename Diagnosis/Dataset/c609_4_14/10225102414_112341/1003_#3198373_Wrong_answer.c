#include <stdio.h>

int main()
{
    int T, n, i = 0, j, a[100];
    scanf("%d", &T);
    for( ;i < T;i++){
        j = 0;
        scanf("%d", &n);
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