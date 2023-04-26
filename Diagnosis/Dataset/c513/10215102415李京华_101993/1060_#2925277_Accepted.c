#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    int i = 0;
    int max = 0;
    while (i < len) {
        while (!isdigit(s[i]) || s[i] == '0')
            i++;
        
        int cnt = 0;
        while (isdigit(s[i])) {
            cnt++;
            i++;
        }
        if (cnt > max)
            max = cnt;
        i++;
    }
    printf("%d", max);
    return 0;
}