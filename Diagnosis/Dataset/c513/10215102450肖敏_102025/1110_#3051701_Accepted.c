#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char s[81];
    scanf("%s", s);
    int len = strlen(s);
    int flag;
    char word;
    double sumnum = 0, sumx = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '=')
            flag = i;//确定=的位置
        if (s[i] >= 'a' && s[i] <= 'z')
            word = s[i];//确定未知数
    }
    int key = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '+' || s[i] == '-' || i == 0 || i == flag + 1) {
            if (s[i] == '+' || s[i] == '-') {
                for (int j = i + 1; s[j] != '+' && s[j] != '-' && j != flag && j < len; j++) {
                    if (s[j] == word) {
                        key = 1;
                        break;
                    }
                }
            } else {
                for (int j = i; s[j] != '+' && s[j] != '-' && j != flag && j < len; j++) {
                    if (s[j] == word) {
                        key = 1;
                        break;
                    }
                }
            }
        }//确定是常数还是未知数系数

        int temp2 = 0, sign = 1;
        if (s[i] == '+' || s[i] == '-' || i == 0 || i == flag + 1) {
            if (s[i] == '+') {
                i++;
            }
            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                temp2 = temp2 * 10 + s[i] - '0';
                i++;
            }
            if (i != 0) {
                i--;
            }
            if (i <= flag) {
                if (key == 1) {
                    sumx = sumx + temp2 * sign;
                    if (temp2 == 0) {
                        sumx = sumx + sign;
                    }
                } else if (key == 0) {
                    sumnum = sumnum - temp2 * sign;
                }
            } else if (i > flag) {
                if (key == 1) {
                    sumx = sumx - temp2 * sign;
                    if (temp2 == 0) {
                        sumx = sumx - sign;
                    }
                } else if (key == 0) {
                    sumnum = sumnum + temp2 * sign;
                }
            }
            key = 0;
        }
    }
    double sum;
    sum = sumnum / sumx;
    printf("%c=%.3lf\n", word, sum);
    return 0;
}
