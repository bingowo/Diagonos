#include <stdio.h>

int main()
{
    char M[] = "0123456789ABCDEFGHIJ", A[20];
    int N, R, i, j, m;
    scanf ("%d%d", &N, &R);
    for (i = 0;N != 0;i++){
        if (N % R >= 0){
            A[i] = M[N % R];
            N /= R;
        }else{
            m = N;
            N = N / R + 1;
            A[i] =  M[m - N * R];
        }
    }
    for (j = i - 1;j >= 0;j--){
        printf("%c", A[j]);
    }
    return 0;
}
