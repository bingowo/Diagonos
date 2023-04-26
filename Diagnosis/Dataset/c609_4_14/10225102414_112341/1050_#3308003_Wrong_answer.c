#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 500

void preprocess(char *a, char *b)
{
    char A[2 * (N + 1)], B[2 * (N + 1)];
    memset(A, '0', sizeof(char) * (2 * (N + 1)));memset(B, '0', sizeof(char) * (2 * (N + 1)));
    if (!strchr(a, '.')) strcat(a, ".");
    if (!strchr(b, '.')) strcat(b, ".");
    strcpy(A + N + 1 - (strchr(a, '.') - a), a);strcpy(B + N + 1 - (strchr(b, '.') - b), b);
    strcpy(a, A);strcpy(b, B);
}

void CalandOutput(char *A, char * B, int T)
{
    int cal, carry = 0, i, j, p;
    for (i = strlen(A) - 1;i >= 0;i--){
        if (A[i] == '.'){
            p = i;continue;
        }
        if (!isdigit(B[i])) cal = A[i] - '0' + carry;
        else cal = A[i] + B[i] - 2 * '0' + carry;
        A[i] = cal % 10 + '0';carry = cal / 10;
    }
    if (carry != 0) A[i] = carry + '0';
    if (A[p + T + 1] > '4') A[p + T] += 1;
    for (j = 0;A[p + T - j] > '9';j++){
        A[p + T - j] = '0';
        if (A[p + T - j - 1] == '.') A[p + T - j++ - 2] += 1;
        else A[p + T - j - 1] += 1;
    }
    if (A[p + T - j] == 1) A[p + T - j] = '1';
    for (j = 0;A[j] == '0';j++);
    for ( ;j < p + T + 1;j++){
        if (A[j] == '\0') printf("0");
        else printf("%c", A[j]);
    }
}

int main()
{
    char A[2 * (N + 1)], B[2 * (N + 1)];int T;
    scanf("%s%s%d", A, B, &T);preprocess(A, B);
    if (strlen(A) > strlen(B)) CalandOutput(A, B, T);
    else CalandOutput(B, A, T);
    return 0;
}
