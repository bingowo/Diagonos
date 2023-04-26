#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define db double
#define ull unsigned long long
int min(int a, int b){ return a > b ? b: a; }
int max(int a, int b){ return a < b ? b: a; }

#define LEN 1006    // 最大位数 + 6 (必须比最大位数稍大一点)

typedef struct {
    int num[LEN];
    int sign;    // 0 认为是正数
} Big;

typedef struct {
    Big quo, rem;
} PBB;

int cmp(Big a, Big b)
{
    // a > b : return 1;
    // a < b : return -1;
    // a = b : return 0;
    if (a.sign != b.sign)
    {
        if (a.sign > b.sign) return 1;
        return -1;
    }
    
    int la = LEN, lb = LEN, flag = a.sign;
    for (; a.num[la - 1] == 0; la--);
    for (; b.num[lb - 1] == 0; lb--);
    if (la < lb) return flag * -1;
    if (la > lb) return flag * 1;
    for (int i = la - 1; i >= 0; i--)
        if (a.num[i] > b.num[i])
            return flag * 1;
        else if (a.num[i] < b.num[i])
            return flag * -1;
    return 0;
}

void clear(Big* a) {
    for (int i = 0; i < LEN; ++i) a -> num[i] = 0;
    a -> sign = 0;
}

void swp(Big* aa, Big* bb)
{
    Big c = *aa;
    *aa = *bb;
    *bb = c;
}

Big read(void) {
    static char s[LEN + 1];
    if (scanf("%s", s) == EOF) exit(0);
    Big a;
    clear(&a);
    int len = strlen(s);
    int i = 0;
    if (s[0] == '-') a.sign = -1, i++;
    else a.sign = 1;
    for (; i < len; ++i) a.num[len - i - 1] = s[i] - '0';
    return a;
}

Big trans(ll x)    // 将 x 转化为 Big 类型
{
    Big a;
    clear(&a);
    if (x < 0) a.sign = -1, x = -x;
    else a.sign = 1;
    int i;
    for (i = 0; x; i++, x /= 10) a.num[i] = x % 10;
    return a;
}

void print(Big a) {    // 输出结果, 注意不会输出换行符, 需要自己加.
    if (a.sign == -1) putchar('-');
    int i;
    for (i = LEN - 1; i >= 1; --i)
        if (a.num[i] != 0) break;
    for (; i >= 0; --i) putchar(a.num[i] + '0');
}

Big add(Big a, Big b) {
    Big c;
    clear(&c);
    if (a.sign * b.sign < 0)
    {
        if (a.sign < 0) swp(&a, &b);
        b.sign = 1;
        if (cmp(a, b) == 0) c = trans(0);
        else {
            int flag = 0;
            if (cmp(a, b) == -1)
                flag = 1, swp(&a, &b);
            for (int i = 0; i < LEN - 1; ++i) {
                c.num[i] += a.num[i] - b.num[i];
                if (c.num[i] < 0) {
                    c.num[i + 1] -= 1;
                    c.num[i] += 10;
                }
            }
            if (flag) c.sign = -1;
            else c.sign = 1;
        }
    }
    else
    {
        for (int i = 0; i < LEN - 1; ++i) {
            c.num[i] += a.num[i] + b.num[i];
            if (c.num[i] >= 10) {
                c.num[i + 1] += 1;
                c.num[i] -= 10;
            }
        }
        if (a.sign == -1) c.sign = -1;
        else c.sign = 1;
    }
    return c;
}

Big sub(Big a, Big b) {
    b.sign *= -1;
    return add(a, b);
}

Big mul(Big a, Big b) {
    Big c;
    clear(&c);
    for (int i = 0; i < LEN - 1; ++i) {
        for (int j = 0; j <= i; ++j) c.num[i] += a.num[j] * b.num[i - j];
        if (c.num[i] >= 10) {
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
        }
    }
    if (a.sign * b.sign == -1) c.sign = -1;
    else c.sign = 1;
    return c;
}

int greater_eq(Big a, Big b, int last_dg, int len) {
    if (a.num[last_dg + len] != 0) return 1;
    for (int i = len - 1; i >= 0; --i) {
        if (a.num[last_dg + i] > b.num[i]) return 1;
        if (a.num[last_dg + i] < b.num[i]) return 0;
    }
    return 1;
}

/* 
因为当被除数与除数的符号出现负数时, 除法的商和余数根据题意的不同会有所不同.
因此, 下面的除法只支持均为正数的Big, 如果需要负数除法, 请自行判断并根据题意处理后再使用下面的函数. 
下面函数返回的商和余数均为Big类型, 且均为正数.
商和余数放在类型PBB中, 商为quo, 余数为second.
注意: 之前已经说过了, 我们认为 0 是正数.
*/
PBB divi(Big a, Big b) {
    Big c, d;
    clear(&c);
    clear(&d);
    int la, lb;
    for (la = LEN - 1; la > 0; --la)
        if (a.num[la - 1] != 0) break;
    for (lb = LEN - 1; lb > 0; --lb)
        if (b.num[lb - 1] != 0) break;
    if (lb == 0) {
        puts("sha7dow o(^-^)o : Divisor is 0");
        return {c, d};
    }
    for (int i = 0; i < la; ++i) d.num[i] = a.num[i];
    for (int i = la - lb; i >= 0; --i) {
        while (greater_eq(d, b, i, lb)) {
            for (int j = 0; j < lb; ++j) {
                d.num[i + j] -= b.num[j];
                if (d.num[i + j] < 0) {
                    d.num[i + j + 1] -= 1;
                    d.num[i + j] += 10;
                }
            }
            c.num[i] += 1;
        }
    }
    c.sign = 1, d.sign = 1;
    return {c, d};
}


int main() {

    while (true)
    {
        Big a = read();
        Big b = read();
        print(sub(a, b));
        puts("");
    }

    return 0;
}