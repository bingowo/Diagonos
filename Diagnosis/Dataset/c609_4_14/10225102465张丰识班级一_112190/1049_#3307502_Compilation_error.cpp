#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define ll long long

#define LEN 1006    // 最大位数 + 6 (必须比最大位数稍大一点)

typedef struct {
    int num[LEN];
    int sign;    // 负数为 -1, 零 为 0, 正数为 1
} Big;

typedef struct {
    Big quo, rem;    // 余数和商
} PBB;


// 下面三个为内部实现的函数, 正常不需要用到.
void clear(Big* a) {
    for (int i = 0; i < LEN; ++i) a -> num[i] = 0;
    a -> sign = 0;
}

void swp(Big* aa, Big* bb) {
    Big c = *aa;
    *aa = *bb;
    *bb = c;
}

int iszero(Big a) {
    for (int i = 0; i < LEN; i++) 
        if (a.num[i] != 0) return 0;
    return 1;
}


// 比较函数 a > b : return 1;  a < b : return -1;  a == b : return 0;
int cmp(Big a, Big b) {
    if (a.sign != b.sign) {
        if (a.sign > b.sign) return 1;
        return -1;
    }
    if (a.sign == 0) return 0;
    int la = LEN, lb = LEN, flag = a.sign;
    for (; a.num[la - 1] == 0; la--);
    for (; b.num[lb - 1] == 0; lb--);
    if (la < lb) return flag * -1;
    if (la > lb) return flag * 1;
    for (int i = la - 1; i >= 0; i--)
        if (a.num[i] > b.num[i]) return flag * 1;
        else if (a.num[i] < b.num[i]) return flag * -1;
    return 0;
}

// 将小整数 x 转化为 Big 类型
Big trans(ll x) {
    Big a;
    clear(&a);
    if (x < 0) a.sign = -1, x = -x;
    else if (x > 0) a.sign = 1;
    else a.sign = 0;
    int i;
    for (i = 0; x; i++, x /= 10) a.num[i] = x % 10;
    return a;
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
    if (iszero(a)) a.sign = 0;
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
    if (a.sign * b.sign <= 0) {
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
    if (iszero(c)) c.sign = 0;
    return c;
}

Big sub(Big a, Big b) {
    b.sign *= -1;
    return add(a, b);
}
int main() {

    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++)
    {
        printf("case #%d:\n", i);
        Big a = read(), res = trans(1);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            res = mul(res, a);
        }
        print(res);
        puts("");
    }
    
    return 0;
}