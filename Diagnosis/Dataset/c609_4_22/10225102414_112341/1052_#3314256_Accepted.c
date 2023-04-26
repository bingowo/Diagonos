#include <stdio.h>
#include <string.h>

void find(int *N)
{
    int A[101] = {0}, i = 0, a = 2;
    while(i < 25){
        if (A[a] == 0){
            N[i++] = a;
            for (int b = 1;a*b < 100;b++) A[a*b] = 1;
        }
        a += 1;
    }
}

void cal(int (*P)[50], int *N, int *I, int i)
{
    P[0][49] = 1 * I[i - 1];
    for (int j = i - 1;j > 0;j--){
        int n = N[j - 1], carry = 0, cal;
        for (int k = 0;n != 0;k++){
            P[j][49 - k] = n % 10;
            n /= 10;
        }
        for (int k = j - 2;k >= 0;k--){
            for (int l = 49;l >= 0;l--){
                cal = P[j][l] * N[k] + carry;
                P[j][l] = cal % 10;
                carry = cal / 10;
            }
        }
        for (int l = 49;l >= 0;l--){
            cal = P[j][l] * I[i - 1 - j] + carry;
            P[j][l] = cal % 10;
            carry = cal /= 10;
        }
    }
    for (int j = i - 1;j > 0;j--){
        int carry = 0, cal, k;
        for (k = 49;k >= 0;k--){
            cal = P[j][k] + P[j - 1][k] + carry;
            P[j - 1][k] = cal % 10;
            carry = cal / 10;
        }
        if (carry != 0) P[j - 1][k] = carry;
    }
}

int main()
{
    int P[25][50], I[25], N[25], i = 0;find(N);
    for (int i = 0;i < 25;i++) memset(P[i], 0, 50 * sizeof(int));
    do{
        scanf("%d", &I[i++]);
    }while (getchar() != '\n');
    if (i == 1 && I[0] == 0) printf("0");
    else{
        cal(P, N, I, i);
        for (i = 0;P[0][i] == 0 && i < 50;i++);
        for ( ;i < 50;i++) printf("%d", P[0][i]);
    }
    printf("\n");
    return 0;
}

