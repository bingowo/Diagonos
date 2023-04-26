#include <stdio.h>
#include <string.h>

void Solve() {
    char s[501];
    scanf("%s", s);
    int cnt = 0, i = 0;
    int flag = 1;
    int len = strlen(s);
    while (i < len) {
        char ch = s[i];
        while (i < len && s[i] == ch) {
            cnt++;
            ++i;
            if (cnt == 255)
                break;
        }
        printf("%d%c", cnt, ch);
        cnt = 0;

    }
    printf("\n");
}

int main() {
    int n, k = 0;
    scanf("%d", &n);
    while (n--) {
        printf("case #%d:\n", k++);
        Solve();
    }
    return 0;
}