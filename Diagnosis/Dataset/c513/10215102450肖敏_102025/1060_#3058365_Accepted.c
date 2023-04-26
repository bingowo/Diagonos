#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    int sum = 1;
    for (int i = 0; i < len; i++) {
        int count = 0;
        int j = i;
        if (s[j] >= '1' && s[j] <= '9') {
            while (s[j] >= '0' && s[j] <= '9') {
                count++;
                j++;
            }
            if (sum < count) {
                sum = count;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
