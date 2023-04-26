#include <stdio.h>
#include <string.h>

#define N 1000

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
    for (i = 0;O[i] == '0';i++);
    if (i == len) i -= 1;
    if (sign == -1) printf("-");
    for ( ;i < len;i++) printf("%c", O[i]);
    printf("\n");
}

int main()
{
    char A[N], B[N];
    while (scanf("%s%s", A, B) != EOF){
        if (strlen(A) > strlen(B)){
            min(A, B);output(A, 1);
        }else if (strlen(A) < strlen(B)){
            min(B, A);output(B, -1);
        }else{
            if (strcmp(A, B) >= 0){
                min(A, B);output(A, 1);
            }else{
                min(B, A);output(B, -1);
            }
        }
    }
    return 0;
}

