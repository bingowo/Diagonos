#include <stdio.h>

int main() {
    char table[] = "0123456789ABCDEFGHIJKL";
    int N, R;
    scanf("%d%d", &N, &R);
    char res[20];
    int len = 0;
    do {
        int temp = N % R;
        N /= R;
        if (temp < 0) {
            temp = temp - R;
            ++N;
        }
        res[len++] = table[temp];
    } while (N);
    for (int i = len - 1; i >= 0; --i)
        printf("%c", res[i]);
    printf("\n");
    return 0;
}