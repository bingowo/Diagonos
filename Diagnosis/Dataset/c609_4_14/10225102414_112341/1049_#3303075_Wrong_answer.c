#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

void plus(char *A, char *B)
{
    int a = strlen(A), b = strlen(B), carry = 0, cal;
    for (int i = 0;i < a;i++){
        if (i >= b) cal = A[a - 1 - i] - '0' + carry;
        else cal = A[a - 1 - i] + B[b - 1 - i] - 2 * '0' + carry;
        A[a - 1 - i] = cal % 10;
        carry = cal / 10;
    }
    if (carry > 0){
        A[a] = '\0';
        for (int j = a - 1;j >= 0;j--) A[j + 1] = A[j];
        A[0] = carry + '0';
    }
}

void min(char *A, char *B)
{
    int a = strlen(A), b = strlen(B), i, j;
    for (i = 0;i < a;i++){
        if (i >= b) continue;
        else if (A[a - 1 - i] - B[b - 1 - i] < 0){
            for (j = 1;A[a - 1 - i - j] == '0';j++) A[a - 1 - i - j] = '9';
            A[a - 1 - i - j] -= 1;
            A[a - 1 - i] = A[a - 1 - i] - B[b - 1 - i] + '0' + 10;
        }else{
            A[a - 1 - i] = A[a - 1 - i] - B[b - 1 - i] + '0';
        }
    }
}

void output(char *O, int sign)
{
    int len = strlen(O), i;
    for (i = 0;O[i] == '0' && len != 1;i++);
    if (sign < 0) printf("-");
    for ( ;i < len;i++) printf("%c", O[i]);
    printf("\n");
}

int main()
{
    char A[N], B[N], *a = A, *b = B;
    while (scanf("%s%s", A, B) != EOF){
        int signa = 1, signb = 1;
        if (A[0] == '-') signa = -1;
        if (B[0] == '-') signb = -1;
        if (signa * signb > 0){
            if (strlen(A) > strlen(B)){
                min(A, B);output(a, signa);
            }else if(strlen(A) == strlen(B)){
                if (strcmp(A, B) > 0){
                    min(A, B);output(a, signa);
                }else{
                    min(B, A);output(b, signa);
                }
            }else{
                min(B, A);output(b, signa);
            }
        }else{
            if (strlen(A) > strlen(B)){
                if (signa == -1){
                    plus(A, B);output(a + 1, signa);
                }else{
                    plus(A, B);output(a, signa);
                }
            }else{
                if (signb == -1){
                    plus(B, A);output(b + 1, signa);
                }else{
                    plus(B, A);output(b, signa);
                }
            }
        }
    }
    return 0;
}

