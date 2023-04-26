#include <stdio.h>
#include <string.h>

int main() {
    char s[1000006];
    int Tab[128] = {0};
    scanf("%s", s);
    int left = 0, right = 1;
    int ans = 0, max = 1;

    Tab[s[0]] = 1;
    int len = strlen(s);
    while (right < len) {
        while (right < len && Tab[s[right]] == 0) {
            Tab[s[right]] = 1;
            right++;
        }

        if (right - left > max) {
            max = right - left;
            ans = left;
        }

        Tab[s[left++]] = 0;
    }

    for (int i = 0; i < max; ++i) {
        printf("%c", s[ans+i]);
    }
    return 0;
}