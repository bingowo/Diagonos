#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int pos, num;
}Dual;

int Count(char *p, char c)
{
    int i;
    for (i = 1;p[i] == c;i++);
    return i;
}

int Delete(char *I)
{
    int i, j, l, n, K = 0, res = 0;
    l = strlen(I);
    for (i = 0;i < l;i++){
        n = Count(I + i, I[i]);
        if (n > 1){
            res += n;
            K = 1;
            for (j = i;j < i + n;j++){
                I[j] = 'D';
            }
            i += n - 1;
        }
    }
    for (i = 0;i < l;i++){
        if (I[i] == 'D'){
            for (j = i + 1;I[j] == 'D' && j < l;j++);
            I[i] = I[j];
            I[j] = 'D';
        }
    }
    for (i = l - res;i <= 102;i++){
        I[i] = '\0';
    }
    if (K == 0){
        return 0;
    }
    return res + Delete(I);
}

int main()
{
    int T, l, i, j, k, n, m, a, large = 0, res;
    Dual P[102];
    char I[102], A, B, C;
    scanf("%d", &T);
    for (i = 0;i < T;i++){
        for (j = 0;j < 102;j++){
            P[j].num = 0;
        }
        scanf("%s", I);
        l = strlen(I);
        k = 0;
        for (j = 0;j < l;j++){
            n = Count(I + j, I[j]);
            for (m = 1;m <= j && I[j - m] == I[j];m++);
            m -= 1;
            n += m;
            if (n == 1){
                P[k++].pos = j;
            }
        }
        for (m = 0;m < k;m++){
            if (P[m].pos == 0 || P[m].pos == l - 1){
                P[m].num = 2;
            }else{
                a = 1;
                A = I[P[m].pos + a];
                B = I[P[m].pos - a];
                C = '\0';
                while (a <= m && m + a < l){
                    if (A == B && A != C && B != C){
                        a += 1;
                        C = A;
                        A = I[P[m].pos + a];
                        B = I[P[m].pos - a];
                    }else{
                        if (A == I[P[m].pos + a - 1] || B == I[P[m].pos - a + 1]){
                            P[m].num -= 1;
                        }
                        break;
                    }
                }
                P[m].num += a * 2;
            }
        }
        large = 0;
        for (j = 0;j < k;j++){
            if (P[j].num > P[large].num){
                large = j;
            }
        }
        for (j = P[large].pos;j < l - 1;j++){
            I[j] = I[j + 1];
        }
        I[j] = '\0';
        res = Delete(I) + 2;
        printf("case #%d:\n%d\n", i, res);
    }
    return 0;
}
