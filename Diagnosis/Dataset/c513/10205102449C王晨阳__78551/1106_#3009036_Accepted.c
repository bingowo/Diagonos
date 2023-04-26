#include <stdio.h>
#include <string.h>

#define MAXN 1010

long long f(char *);

char s[MAXN];

int main() {
    scanf("%s", s);
    long long shu = f(s);
    printf("%d\n", shu);
    return 0;
}

long long f(char *s) {
    int len = strlen(s);
    long long a = 1;
    int is = 0;
    if (len == 1)
        return a;
    if (s[is] != s[is + 1])
        a *= 2;
    is++;
    for (; is < len - 1; is++) {
        if (s[is] != s[is - 1] && s[is] != s[is + 1] && s[is - 1] != s[is + 1])
            a *= 3;
        else if (s[is] == s[is - 1] && s[is] == s[is + 1])
            continue;
        else
            a *= 2;
        if (a > 1000000007)
            a %= 1000000007;
    }
    if (s[is] != s[is - 1])
        a *= 2;
    if (a > 1000000007)
        a %= 1000000007;
    return a;
}
