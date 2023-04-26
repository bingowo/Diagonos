#include<stdio.h>
void trans(int A,char * n,int B) {
    int i, j, s;
    long sum = 0;
    char tmp[30] = {0};
    if (n[0] == '0'&& n[1]==0)
        printf("0\n");
    else {
        for (i = 0; i < strlen(n); i++) {
            if (n[i] >= '0' && n[i] <= '9')sum = sum * A + (n[i] - '0');
            else if (n[i] >= 'a' && n[i] <= 'f')sum = sum * A + (n[i] - 'a' + 10);
            else sum = sum * A + (n[i] - 'A' + 10);
        }
        for (i = 0; sum != 0; i++) {
            s = sum % B;
            sum /= B;
            if (s >= 10)tmp[i] = s - 10 + 'A';
            else tmp[i] = s + '0';
        }
        i = i - 1;
        j = 0;
        while (i >= 0)n[j++] = tmp[i--];
        n[j] = 0;
        printf("%s\n", n);
    }
}
int main() {
    int A, B;
    char n[33];
    scanf("%d%s%d", &A, n, &B);
    trans(A, n, B);
    return 0;
}