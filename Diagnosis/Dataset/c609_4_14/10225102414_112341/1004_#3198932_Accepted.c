#include <stdio.h>
#include <string.h>

int main()
{
    char A[100], B[100] = {0};
    int a, b, i, j, n = 0, m, k = 1;
    scanf("%d%s%d", &a, A, &b);
    for (i = strlen(A) - 1;i >= 0;i--){
        k = 1;
        m = A[i];
        if (m > 64 && m < 91){
            m = m - 55;
        }else if (m > 96 && m < 123){
            m -= 87;
        }else{
            m -= 48;
        }
        for(j = 0;j < strlen(A) - i - 1;j++){
            k *= a;
        }
        n += k * m;
    }
    if(n == 0){
        printf("0");
        return 0;
    }
    for (i = 0;n != 0;i++){
        m = n % b;
        n /= b;
        if (m > 9){
            m += 55;
        }else{
            m += 48;
        }
        B[i] = m;
    }
    for (i -= 1;i >= 0;i--){
        printf("%c", B[i]);
    }
    return 0;
}
