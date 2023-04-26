#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

void plus(char *A, char *B)
{
    int a = strlen(A), b = strlen(B), carry = 0, cal;
    for (int i = 0;i < a;i++){
        if (i >= b) cal = A[i] - '0' + carry;
        else cal = A[i] + B[i] - 2 * '0' + carry;
        A[i] = cal % 10;
        carry = cal / 10;
    }

}

int main()
{
    char A[N], B[N], *a, *b;
    while (scanf("%s%s", A, B) != EOF){
        int signa = 1, signb = 1, len;
        if (A[0] == '-') signa = -1;if(B[0] == '-') signb = -1;
        if (signa * signb > 0){
            if (strlen(A) > strlen(B)) min(A, B);
            else min(B, A);
        }else{
            if (strlen(A) > strlen(B)) plus(A, B);
            else plus(B, A);
        }
        printf("\n");
    }
    return 0;
}
