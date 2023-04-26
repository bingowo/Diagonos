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

int gcd(int x, int y) {
    int r;
    do{
        r = x%y;
        x=y;
        y=r;
    }while(r);
    return x;
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
        len=len*8;int a=gcd(count,len);
        printf("%d/%d\n",count/a,len/a);
    }
    return 0;
}
