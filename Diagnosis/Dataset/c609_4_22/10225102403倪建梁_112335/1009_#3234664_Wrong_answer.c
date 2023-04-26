#include <stdio.h>
#include <string.h>

int count_bits(char c) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (c & (1 << i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // 读入换行符
    for (int i = 0; i < n; i++) {
        char s[121];
        fgets(s, sizeof(s), stdin);
        int len = strlen(s) - 1; // 去掉末尾的换行符
        int count = 0;
        for (int j = 0; j < len; j++) {
            count += count_bits(s[j]);
        }
        double density = count / (double)(len * 8);
        // 将分数进行约分
        for (int j = 2; j <= 1000; j++) {
            if (density * j == (int)(density * j)) {
                int numerator = (int)(density * j);
                int denominator = j;
                printf("%d/%d\n", numerator, denominator);
                break;
            }
        }
    }
    return 0;
}
