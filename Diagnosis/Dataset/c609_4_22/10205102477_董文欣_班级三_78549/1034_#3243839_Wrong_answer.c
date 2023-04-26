#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100001];

int main()
{
    scanf("%s",s);
    int len = strlen(s);
    unsigned int ans = 0;
    for (int i = 2; i < len; i++) {
        ans = 0;
        if (s[i-2] == '0' && s[i-1] == 'x') {
            while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f')) {
                if (s[i] >= '0' && s[i] <= '9') {ans = ans * 16 + (s[i] - '0'); i++;}
                else if (s[i] >= 'a' && s[i] <= 'f') {ans = ans * 16 + (s[i] - 'a' + 10); i++;}
                else break;
            }
        }
        if (ans) printf("%u ",ans);
    }

    if (!ans) printf("-1");
    return 0;
}
