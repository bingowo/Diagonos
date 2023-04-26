#include <stdio.h>
#include <string.h>

unsigned long long cal(int n, int R)
{
    int i;
    unsigned long long re = 1;
    for (i = 0;i < n - 1;i++){
        re *= R;
    }
    return re;
}

int main()
{
    int T, R, i, j, k, l, num, n[60], S[60];
    unsigned long long a;
    char M[60], N[60];
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        l = 0;
        a = 0;
        memset(N, 0, 60);
        scanf("%s", M);
        for (j = 0;j < strlen(M);j++){
            for (k = 0;k < strlen(N);k++){
                if(M[j] == N[k]){
                    break;
                }
            }
            if (k == strlen(N)){
                N[l] = M[j];
                l += 1;
            }
        }
        R = strlen(N);
        n[0] = 1;
        n[1] = 0;
        num = 2;
        for (l = 2;l < R;l++){
            n[l] = num++;
        }
        for (l = 0;l < strlen(M);l++){
            for(int h = 0;h < strlen(N);h++){
                if (N[h] == M[l]){
                    S[l] = n[h];
                }
            }
        }
        for (int h = --l;h >= 0;h--){
            a += S[h] * cal(l - h + 1, R);
        }
        printf("case #%d:\n%llu\n", i, a);
    }
}
