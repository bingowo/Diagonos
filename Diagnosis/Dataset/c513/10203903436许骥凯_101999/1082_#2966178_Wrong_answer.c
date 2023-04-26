#include<stdio.h>
#include<string.h>

#define N 500

void input(int *a){
    char s[N + 1];
    scanf("%s", s);
    int i = 0;
    while(s[i] && s[i] != '.') i++;
    for (int j = i - 1, k = N; j >= 0; j--, k--)
        a[k] = s[j] - '0';
    for (int j = i + 1, k = N + 1; j < strlen(s); j++, k++)
        a[k] = s[j] - '0';
}

void add(int *a, int *b, int pre){
    for (int i = 2 * N; i > N + pre; i--){
        a[i] += b[i];
        a[i-1] += a[i] / 10;
        a[i] %= 10;
    }
    if (a[N + pre] >= 5) a[N + pre]++;
    for (int i = N + pre; i > 0; i--){
        a[i] += b[i];
        a[i-1] += a[i] / 10;
        a[i] %= 10;
    }
}

void output(int *a, int pre){
    int i = 0;
    while(i <= N && a[i] == 0) i++;
    if (i > N) printf("0");
    else while(i <= N) printf("%d", a[i++]);
    printf(".");
    while(i <= N + pre) printf("%d", a[i++]);
    printf("\n");
}


int main(){
    int A[2 * N + 1] = {0}, B[2 * N + 1] = {0}, pre;
    input(A); input(B); scanf("%d", &pre);
    add(A, B, pre);
    output(A, pre);
    return 0;
}