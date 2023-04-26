#include <stdio.h>
#include <string.h>

int jilu[1001];
int jie[3005];
int count;

void trans(int *array) {
    count = 0;
    int flag = 1;
    for (int i = 3004; i > 0; i--) {
        array[i - 1] += array[i] / 10;
        array[i] %= 10;
        if (array[i] == 0 && flag)
            count++;
        else
            flag = 0;
    }
}

void multi(int *array, int num) {
    for (int i = 3004; i > 0; i--) {
        array[i] *= num;
    }
    trans(array);
}

int main() {
    int T;
    scanf("%d", &T);
    memset(jie, 0, sizeof(jie));
    jie[3004] = 1;
    for (int i = 1; i <= 1000; i++) {
        multi(jie, i);
        jilu[i] = count;
    }
    for (int i = 0; i < T; ++i) {
        printf("case #%d:\n",i);
        int n;
        scanf("%d", &n);
        printf("%d\n",jilu[n]);
    }
    return 0;
}
