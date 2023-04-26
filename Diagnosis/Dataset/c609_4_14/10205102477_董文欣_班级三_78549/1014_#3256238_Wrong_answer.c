#include <stdio.h>
int main(){
    long long int a, b, c, d;
    scanf("%lld %lld", &a, &b);
    c = a / b; d = a % b;
    int s[60] = {0}, s1[30] = {0}, s2[30] = {0};
    int cnt1 = 1, cnt2 = 1;
    while (c) {
        s1[cnt1++] = c % 3;
        c /= 3;
    }
    int i = 1, tmp = cnt1;
    for (i = 1; i < cnt1; i++) {
        s[i] = s1[--tmp];
    }
    i++; //小数点
    while (d) {
        s2[cnt2++] = d % 3;
        d /= 3;
    }
    tmp = cnt2; i = i - 1;
    while (tmp) {
        s[i] = s2[--tmp];
        i++;
    }
    int len = i - 1; i--;
//将得到的三进制数与全1序列按 三进制记数系统的规则 相加
    while (i > 0) {
        i--;
        s[i] += 1;
        if (s[i] >= 3)
        {
            s[i - 1] += 1;
            s[i] -= 3;
        }
    }
//将第2步得到的序列与全1序列按位独立相减
    i = 0;
    while (i < len) {
        s[i] -= 1;
        if (s[i] == -1) s[i] = 2;
        i++;
    }
    //输出
    if (s[0]) {
        for (i = 0; i < cnt1; i++) {
            printf("%d", s[i]);
        }
        if (cnt2 != 1) {
            printf(".");
            for (i = cnt1; i < cnt2 + cnt1 - 1; i++) {
                printf("%d", s[i]);
            }
        }
    }
    else {
        for (i = 1; i < cnt1; i++) {
            printf("%d", s[i]);
        }
        printf(".");
        for (i = cnt1; i < cnt2 + cnt1 - 1; i++) {
            printf("%d", s[i]);
        }
    }


    return 0;
}
