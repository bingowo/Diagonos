#include <stdio.h>

int main()
{
    int B[100], T, n, i, j, a, re;
    scanf("%d", &T);
    for(i = 0;i < T;i++){
        a = 1;
        re = 1;
        scanf("%d", &n);
        if (n == 0){
            printf("case #%d:\n0\n", i);
            continue;
        }
        for (j = 0;n != 0;j++){
            B[j] = n % 2;
            n /= 2;
        }
        for (j -= 1;j > 0;j--){
            if (B[j] == 1){
                if (B[j - 1] == 0){
                    a += 1;
                }else{
                    if (re < a){
                        re = a;
                    }
                    a = 1;
                    continue;
                }
            }else{
                if (B[j - 1] == 1){
                    a += 1;
                }else{
                    if (re < a){
                        re = a;
                    }
                    a = 1;
                    continue;
                }
            }
            if (re < a){
                re = a;
            }
        }
        printf("case #%d:\n%d\n", i, re);
    }
    return 0;
}