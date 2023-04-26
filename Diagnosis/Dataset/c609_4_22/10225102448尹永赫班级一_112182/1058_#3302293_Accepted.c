#include <stdio.h>
#include <string.h>

int num[110], flag = 1, len1 = 0, pos = 0, ans[1100], len2 = 0;

void numAdd1() {//num+1
    int temp = 1, ret = len1 - 1;
    while (temp != 0) {
        num[ret] += temp;
        temp = num[ret] / 10;
        num[ret--] %= 10;
    }
    if (ret < pos) pos = ret;
}

void numDivide2() {//num/2
    int ret, temp = num[pos];
    while (temp < 2) {//寻找除2之后的最高位
        num[pos++] = 0;
        if (pos == len1) return;
        temp = temp * 10 + num[pos];
    }
    ret = pos;
    while (ret < len1) {
        num[ret++] = temp / 2;
        temp %= 2;
        while (temp < 2 && ret < len1) {
            temp = temp * 10 + num[ret];
            num[ret++] = 0;
            if (temp >= 2) ret--;
        }
    }
}

int main() {
    char s[110];
    scanf("%s", s);
    len1 = strlen(s);
    if (s[0] == '-') {
        flag *= -1;
        pos++;
    }
    for (int i = pos; i < len1; i++) {
        num[i] = (int) s[i] - 48;
    }
    while (pos < len1) {
        if (num[len1 - 1] % 2 == 1) ans[len2++] = 1;
        else ans[len2++] = 0;
        if (flag == -1) { //若被除数也为负数，数值上加一(不算符号)
            numAdd1();
        }
        numDivide2();
        flag *= -1;
    }
    for (int i = 0; i < len2; i++) {
        printf("%d", ans[len2 - 1 - i]);
    }
    return 0;
}

