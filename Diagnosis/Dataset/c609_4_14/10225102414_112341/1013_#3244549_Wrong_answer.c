#include <stdio.h>
#include <string.h>

long long cal(int n)
{
    long long x = 1;
    for (int i = 0;i < n;i++){
        x = x * (-4);
    }
    return x;
}

int main()
{
    char H[16] = "0123456789ABCDEF", S[100];
    int m, i, j, k, l, x, y, N[100] = {0};
    long long a, b;
    scanf("%s", S);
    l = strlen(S);
    for (i = l - 1;i > 1;i--){
        for (j = 0;H[j] != S[i];j++);
        N[i] = j;
    }
    a = 0;b = 0;
    for (m = l - 1;m > 1;m--){
        x = 0;y = 0;
        for (i = 0;i < N[m];i++){
            if (i % 2 == 0){
                x += 1;
            }else if((i + 1) % 4 == 0){
                for (k = 0;3 + k * 4 != i;k++);
                if (k % 2 == 1){
                    x += 2 * k;
                    y += 3;
                }else{
                    y -= 3;
                }
            }else{
                x -= 2;
                y += 1;
            }
        }
        a += x * cal(l - 1 - m);
        b += y * cal(l - 1 - m);
    }
    if (a == 0 && b == 0){
        printf("0");
    }else if (a == 0 && b != 0){
        if (b != 1){
            printf("%lldi", b);
        }else{
            if (b == 1){
                printf("i");
            }else{
                printf("-i");
            }
        }
    }else if(b == 0 && a != 0){
        printf("%lld", a);
    }else if (b > 0){
        if (b != 1){
            printf("%lld+%lldi",a, b);
        }else{
            printf("%lld+i", a);
        }
    }else{
        if (b != -1){
            printf("%lld%lldi", a, b);
        }else{
            printf("%lld-i", a);
        }
    }
    return 0;
}
