#include <stdio.h>
#include <math.h>
void solve(int a, double b) {
    char A[32];
    int cnt = 0;
    b = log(b) / log(3);    //
    A[(int)b] = '.';
    int i;

    while (a){
        if (cnt == b)
            ++cnt;
        else{
            A[cnt++] = a % 3 + '0';
            a /= 3;
        }
    }
    while (cnt < b)
        A[cnt++] = '0';
    if (cnt == b && cnt != 0){
        ++cnt;
        A[cnt++] = '0';
    }

    int res;
    int Carry = 0;
    for (i = 0; i < cnt; ++i) {
        if (i == b)
            continue;
        else {
            res = A[i] - '0' + 1 + Carry;
            if (res >= 3) {
                A[i] = res - 3 + '0';
                Carry = 1;;
            }
            else {
                A[i] = res + '0';
                Carry = 0;
            }
        }
    }
    if (Carry == 1)
        A[cnt++] = '1';

    for (i = 0; i < cnt; ++i) {
        if (i == b) {
            continue;
        }
        else {
            if (i == cnt - 1 && A[i] == '1')
                break;
            res = A[i] - '0' - 1;
            if (res == -1) {
                A[i] = '2';
            }
            else {
                A[i] = res + '0';
            }
        }

    }

    if (cnt == 0)
        printf("0");
    else{
        while (A[cnt-1] == '0')
            --cnt;
        for (i= cnt - 1; i > 0; --i)
            printf("%c", A[i]);
        if (A[0] != '.')
            printf("%c", A[0]);
    }
}

int main(){
    int a;
    double b;
    scanf("%d%lf", &a, &b);
    solve(a, b);
    return 0;
}