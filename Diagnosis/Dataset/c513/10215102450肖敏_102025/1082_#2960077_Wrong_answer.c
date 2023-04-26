#include <stdio.h>
#include <string.h>

#define N 500
typedef struct {
    int cnt, v[N];
} BIGINT;

BIGINT ADD(BIGINT S, BIGINT T) {
    BIGINT R = {0};
    int i, carry = 0;
    for (i = 0; i < S.cnt && i < T.cnt; i++) {
        int temp = (S.v[i] + T.v[i] + carry);
        R.v[i] = temp % 10;
        carry = temp / 10;
    }
    while (i < S.cnt) {
        int temp = S.v[i] + carry;
        R.v[i++] = temp % 10;
        carry = temp / 10;
    }
    while (i < T.cnt) {
        int temp = T.v[i] + carry;
        R.v[i++] = temp % 10;
        carry = temp / 10;
    }
    if (carry) {
        R.v[i++] = carry % 10;
    }
    R.cnt = i;
    return R;
}


int main() {
    int n;
    char A[501], B[501];

    scanf("%s",A);
    scanf("%s",B);
    scanf("%d", &n);
    int len1 = strlen(A), len2 = strlen(B);
    int i, a, b, j;
    for (i = 0; i < len1; i++) {
        if (A[i] == '.')
        {
            a = i;
            break;
        }
    }
    for (i = 0; i < len2; i++) {
        if (B[i] == '.')
        {
            b = i;
            break;
        }
    }
    BIGINT AI = {0}, AF = {0}, BI = {0}, BF = {0};
    for (j = 0, i = a - 1; i >= 0; i--, j++) {
        AI.v[j] = A[i] - '0';
        AI.cnt++;
    }
    for (i = len1 - 1, j = 0; i > a; i--, j++) {
        AF.v[j] = A[i] - '0';
        AF.cnt++;
    }
    for (j = 0, i = b - 1; i >= 0; i--, j++) {
        BI.v[j] = B[i] - '0';
        BI.cnt++;
    }
    for (i = len2 - 1, j = 0; i > b; i--, j++) {
        BF.v[j] = B[i] - '0';
        BF.cnt++;
    }
    BIGINT I, R;
    I = ADD(AI, BI);
    R = ADD(AF, BF);
    if (R.v[R.cnt - n - 1] >= 5) {
        for (int k = R.cnt - n; k <= R.cnt; k++) {
            if (R.v[k] == 9)
                R.v[k] = 0;
            else {
                R.v[k] += 1;
                break;
            }
        }
    }
    for (int k = I.cnt - 1; k >= 0; k--)
        printf("%d", I.v[k]);
    printf(".");
    for (int k = R.cnt - 1; k >= R.cnt - n; k--)
        printf("%d", R.v[k]);
    printf("\n");
    return 0;
}
