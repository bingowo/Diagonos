#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(c)
{
    if (c >= '0' && c <= '9' || c >= 'a' && c <= 'e') return 1;
    return 0;
}

unsigned int toDigit(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    else {
        return c - 'a' + 10;
    }
}

int main()
{
    char str[100020] = {0};
    scanf("%s", str);
    unsigned int ans = 0;
    int status = 0;
    int cnt = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (i < len-1 && str[i] == '0' && str[i+1] == 'x') {
            status = 1;
            i++;
        }
        else if (status == 1 && check(str[i])) {
            ans *= 16;
            ans += toDigit(str[i]);
        }
        else if (status == 1 && !check(str[i])) {
            status = 0;
            printf("%u ", ans);
            ans = 0;
            cnt++;
        }
        else if (status == 0 && !check(str[i])) {

        }
    }
    if (ans != 0) printf("%u ", ans);
    if (cnt == 0) printf("-1");
    return 0;
}
